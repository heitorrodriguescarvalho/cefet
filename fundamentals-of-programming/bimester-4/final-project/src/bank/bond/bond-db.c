#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "bond-db.h"
#include "../bank-account/bank-account-db.h"
#include "../../menu/menu.h"
#define BONDS_NUM 20

// Database
Bond bonds[BONDS_NUM];
int last_bond_index = -1;

// Databse functions
Bond *Create_bond(char name[], char rate_label[], double annual_interest_rate)
{
  time_t now;

  last_bond_index++;

  bonds[last_bond_index].annual_interest_rate = annual_interest_rate;
  strcpy(bonds[last_bond_index].name, name);
  strcpy(bonds[last_bond_index].rate_label, rate_label);
  bonds[last_bond_index].last_update_at = time(&now);

  return &bonds[last_bond_index];
}

Bond Get_bond_by_index(int index)
{
  return bonds[index];
}

Bond Get_bond_by_name(char name[])
{
  int i;

  for (i = 0; i < last_bond_index; i++)
    if (strcmp(name, bonds[i].name) == 0)
      return bonds[i];
}

int Count_bonds()
{
  return last_bond_index;
}

void Buy_bond(char bond_name[], double value, float time_in_years)
{
  time_t now;
  Bond bond = Get_bond_by_name(bond_name);
  Bank_account *bank_account = Get_current_bank_account();

  time(&now);

  bank_account->last_bond_index++;

  bond.last_update_at = now;
  bond.total_months_to_expire = (int)ceil(time_in_years * 12);
  bond.investment_value = value;

  bank_account->balance -= value;
  bank_account->bonds[bank_account->last_bond_index] = bond;
}

// Bonds logic
void Update_bonds()
{
  int i, num_receipts;
  Bank_account *bank_account = Get_current_bank_account();
  time_t now;
  Bond *bond;

  time(&now);

  for (i = 0; i <= bank_account->last_bond_index; i++)
  {
    bond = &bank_account->bonds[i];

    if (bond->months_expired == bond->total_months_to_expire)
      continue;

    num_receipts = (int)floor(difftime(now, bond->last_update_at) / 60);

    if (num_receipts == 0)
      continue;

    if (bond->months_expired + num_receipts >= bond->total_months_to_expire)
    {
      num_receipts = bond->total_months_to_expire - bond->months_expired;

      bank_account->balance += bond->investment_value;
    }

    bond->months_expired += num_receipts;
    bond->last_update_at = now;

    bank_account->balance += (bond->annual_interest_rate / 12) * bond->investment_value * num_receipts;
  }
}

void Initialize_bonds()
{
  char names[BONDS_NUM][26] = {
      "CDB Prefixado 1 ano", "CDB Pós-fixado CDI", "Tesouro Selic", "Tesouro IPCA+ 2030",
      "Tesouro Prefixado 2026", "LCI Prefixada", "LCA Pós-fixada", "Fundo Renda Fixa Simples",
      "Fundo DI", "Poupança", "Debênture Prefixada", "Debênture IPCA+", "CRI Pós-fixado",
      "CRA Prefixado", "Tesouro IPCA+ 2045", "CDB Liquidez Diária", "Tesouro Prefixado 2033",
      "Fundo Renda Fixa Crédito", "LCI IPCA+", "LCA Prefixada"};

  char rate_labels[BONDS_NUM][26] = {
      "10% ao ano (fixa)", "100% do CDI", "Taxa Selic diária", "IPCA + 5,5% ao ano",
      "12% ao ano (fixa)", "9% ao ano (fixa)", "95% do CDI", "Taxa média do CDI - 0,5%",
      "100% do CDI", "70% da Selic + TR", "11% ao ano (fixa)", "IPCA + 6,5% ao ano",
      "110% do CDI", "10% ao ano (fixa)", "IPCA + 5,2% ao ano", "98% do CDI",
      "11,5% ao ano (fixa)", "105% do CDI", "IPCA + 4,5% ao ano", "9,5% ao ano (fixa)"};

  float rates[BONDS_NUM] = {
      10.0,  // "10% ao ano (fixa)"
      14.25, // "100% do CDI" (aproximadamente igual à taxa Selic)
      14.25, // "Taxa Selic diária"
      19.75, // "IPCA + 5,5% ao ano" (IPCA estimado em 14.25% + 5.5%)
      12.0,  // "12% ao ano (fixa)"
      9.0,   // "9% ao ano (fixa)"
      13.54, // "95% do CDI" (0.95 * 14.25)
      13.54, // "Taxa média do CDI - 0,5%" (14.25 - 0.5)
      14.25, // "100% do CDI"
      10.11, // "70% da Selic + TR" (0.70 * 14.25 + 0.16)
      11.0,  // "11% ao ano (fixa)"
      20.75, // "IPCA + 6,5% ao ano" (IPCA estimado em 14.25% + 6.5%)
      15.68, // "110% do CDI" (1.10 * 14.25)
      10.0,  // "10% ao ano (fixa)"
      19.45, // "IPCA + 5,2% ao ano" (IPCA estimado em 14.25% + 5.2%)
      13.96, // "98% do CDI" (0.98 * 14.25)
      11.5,  // "11,5% ao ano (fixa)"
      14.96, // "105% do CDI" (1.05 * 14.25)
      18.75, // "IPCA + 4,5% ao ano" (IPCA estimado em 14.25% + 4.5%)
      9.5    // "9,5% ao ano (fixa)"
  };

  for (int i = 0; i < BONDS_NUM; i++)
    Create_bond(names[i], rate_labels[i], rates[i] / 100);
}