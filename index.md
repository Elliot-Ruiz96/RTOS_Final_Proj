# **RTOS Final Project: Clock**

Hernández-Romero B. Ruiz-Sánchez E.

**Centro de Investigación y de Estudios Avanzados del IPN. Zapopán, Jal, México.**

![1](https://user-images.githubusercontent.com/78750648/131061290-1aff4f6a-679c-4579-a347-c069272e0be0.png)

## **1. Introducción**

El codigo fue generado con la herramienta MCUxpreso IDE v.11.3.1 para la tarjeta de desarrollo Freedoom Development Board K64 kinetis. El proyecto consiste en un relog digital, al cual se le puede programar una alarma, este reloj será mostrado por medio de una pantalla LCD Nokia 5110. Utilizando la librería de FreeRTOS se genera el funcionamineto del reloj por medio de tareas con diferentes prioridades.

![2](https://user-images.githubusercontent.com/78750648/131061861-4aa66916-65c5-448b-9d08-9eb4e4e324d4.JPG)

*Figura 1. Diagrama de bloques* 

## **2. Descripción del código**

### *2.1  main.c*

Línea 33 - Línea 52: Mandamos llamar todas las librerías de drives que se utilizarán para el proyecto. 

Línea 55 - Línea 59: Declaramos las estrucutruas a utilizar con nombres convenientes.

Línea 61 - Línea 71: Utilización de código genérico para funcionamiento de RTOS en el tarjeta.

Línea 73 - Línea 77: Manipulador de funciones

Línea 79: Añadir registro de tiempo a la cola

Línea 81: Definir la estrucutura de la alarma

Línea 83 - Línea 77: Creación de MACROS y se añaden los registros a las colas

Línea 89 - Línea 97: Creación de la tarea Idle junto con las otras 5, ademas de sus proridades respectivas (donde la tarea "horas" es la más importante de estas cinco)

Últimas líneas de código: Apagado y encendido de la luz de fondo de la pantalla.

### *2.2 freertos_spi.c*



### *2.3 freertos_spi.h*



### *2.4 RTOS_FProject.c*

Línea 45 - Línea 92:  Funcionamiento de toda la tarea de segundos;
                      Pone la base de tiempo para la ejecución de todo el proyecto, para el funcaionamiento del semáforo entre horas, mins y segs.
                      Dentro está la validación para la ejecución de la alarma, el regresar la variable a 0 cada que llegue a 59.
                      
Línea 94 - Línea 133:   Funcionamiento de toda la tarea de minutos;
                        Es un proceso similar a la tarea anterior, cada que termine la tarea anterior (segundos) el semáforo da paso a los minutoa
                        Dentro está la validación para la ejecución de la alarma, el regresar la variable a 0 cada que llegue a 59.                      

Línea 135 - Línea 173:  Funcionamiento de toda la tarea de horas;
                        Es un proceso similar a la tarea anterior, cada que termine la tarea anterior (minutos) el semáforo da paso a las horas
                        Dentro está la validación para la ejecución de la alarma, el regresar la variable a 0 cada que llegue a 23 (cada que los tres eventos sean completados) 
                          
Línea 175 - Línea 246:  Funcionamiento de toda la tarea de segundos;
                        Creación de banderas para el encendido y pagado de la pantalla
                        Validación de los tres eventos para que el semáforo deje pasar a la tarea, con la bandera blacklight se genera el apago y encendido de la pantalla.
                        Recordar siempre usar el UpdateDisplay para mostrar en la pantalla.
                        
Línea 148 - Línea 293:  Funcionamiento de la impresión del reloj digital;
                        Se tendran 9 valores en un solo arreglo para mostrar los 6 números, los dos puntos y uno adicional en la última posición
                        
Línea 295 - Línea 316:  Conversión de entero a ASCII;
                        Recordar que un char es solo un entero sin signo
                        Se toma la siguiente tabla para generar la conversión:
                        
![3](https://user-images.githubusercontent.com/78750648/131067708-17735ea8-e202-47d1-ad0b-44b4f5cfe3cb.JPG)

### *2.5 RTOS_FProject.h*

Línea 24 - Línea 39: Definimos MACRSO para los bits, inicialización del reloj, config de la alarma y el "tiempo en que prende y apaga la pantalla"

Línea 43 - Línea 56: Definición de las estrucuturas

Línea 60 - Línea 65: Definición de todas las task a usar

Línea 68: Conversión de entero a tipo ASCII

### *2.6 nokiaLCD.h Y nokiaLCD.c*

Son los archivos utilziados originalmente, no hay cambios importantes en este header ni source.

## **3. Resultados y discusión**

[![237785289_1312303532555244_6905168508972581288_n](https://user-images.githubusercontent.com/78750648/131064272-a7f0e32f-1a90-4e3c-a59c-b140c4c4abd4.png)](https://drive.google.com/file/d/11De023Jxu4Roi6CscvxIsyxqTosrB-H_/view?usp=sharing)

## **4. Conclusiones**

Este proyecto da una idea muy básica de como funcionan estos códigos en las aplicaciones reales. Algo muy importante por mencionar es que siempre habrán defectos, pero estos siempre se podrán minimizar conforme el usuario/desarrollador vaya tomando experiencia y se usen metodologías buenas para el diseño junto conm metodologías de calidad.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

TEST

[![Watch the video](https://img.youtube.com/vi/6DeDzsCGbsQ/maxresdefault.jpg)](https://youtu.be/6DeDzsCGbsQ)
