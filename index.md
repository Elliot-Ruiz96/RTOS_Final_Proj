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

Línea 55 - Línea 59: Declaramos las estrucutruas a utilizar con nombres convenientes

Línea 61 - Línea 71: Utilización de código genérico para funcionamiento de RTOS en el tarjeta.

Línea 73 - Línea 77: Manipulador de funciones

Línea 79: Añadir registro de tiempo a la cola

Línea 81: Definir la estrucutura de la alarma

Línea 83 - Línea 77: Creación de MACROS y se añaden los registros a las colas

Línea 89 - Línea 97: Creación de la tarea Idle junto con las otras 5, ademas de sus proridades respectivas (donde la tarea "horas" es la más importante de estas cinco)

Últimas líneas de código: Apagado y encendido de la luz de fondo de la pantalla.

### *2.2 freertos_spi.c*

Por medio de la plataforma SwissParam, se obtuvieron los archivos necesarios para realizar la dinámica molecular, para su posterior ejecución empleando Gromacs 2021 GPU mediante la plataforma Google Colab donde se efectuaron los pasos necesarios para el acondicionamiento y subsiguiente análisis de dinámica molecular.

### *2.3 freertos_spi.h*



### *2.4 nokiaLCD.h Y nokiaLCD.c*

Son los archivos utilziados originalmente, no hay cambios importantes en este header ni source.

## **3. Resultados y discusión**

[![237785289_1312303532555244_6905168508972581288_n](https://user-images.githubusercontent.com/78750648/131064272-a7f0e32f-1a90-4e3c-a59c-b140c4c4abd4.png)](https://drive.google.com/file/d/11De023Jxu4Roi6CscvxIsyxqTosrB-H_/view?usp=sharing)

## **4. Conclusiones**

## **5. Bibliografía**

![237785289_1312303532555244_6905168508972581288_n](https://user-images.githubusercontent.com/78750648/131064272-a7f0e32f-1a90-4e3c-a59c-b140c4c4abd4.png)
