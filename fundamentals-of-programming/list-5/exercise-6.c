#include <stdio.h>
#include <stdlib.h>

main() {
  int maxSpeed, driverSpeed;
  float penalty;

  printf("Digite a velocidade máxima da via (km/h): ");
  scanf("%d", &maxSpeed);

  printf("Digite a velocidade em que o motorista estava dirigindo (km/h): ");
  scanf("%d", &driverSpeed);

  if (driverSpeed - maxSpeed <= 0)
    penalty = 0.0;
  else if (driverSpeed - maxSpeed <= 10)
    penalty = 50.0;
  else if (driverSpeed - maxSpeed <= 30)
    penalty = 100.0;
  else
    penalty = 200.0;

  printf("Valor da multa: R$%.2f", penalty);
}