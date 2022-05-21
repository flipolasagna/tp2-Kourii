Proceso Dado electronico
	incialización del micro
	cont = 0
	flag_bt1 = 0
	mostrar_led
	Mientras 1==1 Hacer
		Si bot==0 Entonces
			flag_bt1 = 1
		FinSi
		Si flag_bt1== 1 Entonces
			cont++
			Si cont==7 Entonces
				cont = 1
			FinSi
			mostrar_led(cont)
			delay(100)
		FinSi
		Si bot2==0 Entonces
			flag = 0
		FinSi
		Si bot3==0 | bot4==0 Entonces
			apagar todos los leds
		FinSi
	FinMientras
	mostrar_leds
	apagar todos los leds
	Si switch Entonces
		Si case1: Entonces
			encender forma 1
		FinSi
		Si case 2: Entonces
			encender forma 2
		FinSi
		Si case 3: Entonces
			encender forma 3
		FinSi
		Si case 4: Entonces
			encender forma 4
		FinSi
		Si case 5: Entonces
			encender forma 5
		FinSi
		Si case 6: Entonces
			encender forma 6
		FinSi
	FinSi
FinProceso
