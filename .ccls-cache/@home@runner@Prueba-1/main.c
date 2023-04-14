#include <stdio.h>

float calcular_salario_bruto(int horas_trabajadas, float valor_por_hora) {
    int horas_extra_10 = 0, horas_extra_15 = 0, horas_extra_20 = 0;
    float salario_bruto;

    if (horas_trabajadas > 40) {
        int horas_extra = horas_trabajadas - 40;
        if (horas_extra <= 10) {
            horas_extra_10 = horas_extra;
        } else if (horas_extra <= 15) {
            horas_extra_10 = 10;
            horas_extra_15 = horas_extra - 10;
        } else {
            horas_extra_10 = 10;
            horas_extra_15 = 5;
            horas_extra_20 = horas_extra - 15;
        }
    }

    salario_bruto = (40 * valor_por_hora) + (horas_extra_10 * valor_por_hora * 1.1) + (horas_extra_15 * valor_por_hora * 1.15) + (horas_extra_20 * valor_por_hora * 1.2);

    return salario_bruto;
}

float calcular_bonificaciones(float monto_ventas) {
    float bonificacion;

    if (monto_ventas <= 800) {
        bonificacion = monto_ventas * 0.02;
    } else if (monto_ventas <= 1500) {
        bonificacion = monto_ventas * 0.04;
    } else if (monto_ventas <= 3000) {
        bonificacion = monto_ventas * 0.06;
    } else {
        bonificacion = monto_ventas * 0.08;
    }

    return bonificacion;
}

float calcular_salario_neto(int horas_trabajadas, float valor_por_hora, float monto_ventas) {
    float salario_bruto, bonificacion, aporte_iess, salario_neto;

    salario_bruto = calcular_salario_bruto(horas_trabajadas, valor_por_hora);
    bonificacion = calcular_bonificaciones(monto_ventas);
    aporte_iess = salario_bruto * 0.0945;
    salario_neto = salario_bruto - aporte_iess + bonificacion;

    return salario_neto;
}

int main() {
    int horas_trabajadas;
    float valor_por_hora, monto_ventas, salario_bruto, bonificacion, salario_neto;

    printf("Ingrese el total de horas trabajadas: ");
    scanf("%d", &horas_trabajadas);
    printf("Ingrese el valor por hora: ");
    scanf("%f", &valor_por_hora);
    printf("Ingrese el monto de ventas: ");
    scanf("%f", &monto_ventas);

    salario_bruto = calcular_salario_bruto(horas_trabajadas, valor_por_hora);
    bonificacion = calcular_bonificaciones(monto_ventas);
    salario_neto = calcular_salario_neto(horas_trabajadas, valor_por_hora, monto_ventas);

    printf("Salario neto: %.2f\n", salario_neto);

    return 0;
      }