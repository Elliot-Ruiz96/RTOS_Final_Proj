# **RTOS Final Project: Clock**

https://elliot-ruiz96.github.io/RTOS_Final_Proj/

Hernández-Romero B. Ruiz-Sánchez E.

**Centro de Investigación y de Estudios Avanzados del IPN. Zapopán, Jal, México.**

![1](https://user-images.githubusercontent.com/78750648/131061290-1aff4f6a-679c-4579-a347-c069272e0be0.png)

## **1. Introducción**

La emergencia sanitaria causada por la COVID-19 (Coronavirus disease-2019) ha cobrado hasta principios de agosto 256,246 vidas (CONACYT, 2020) debido a la falta de un tratamiento, encendiendo las alarmas sanitarias a nivel mundial desde el inicio de la pandemia; aún con la aplicación de vacunas aprobadas por emergencia sanitaria, tan sólo el 24.2% de la población mundial ha sido inmunizada (Mathieu, E. et al. 2021), sin mencionar que sólo funcionan como medio preventivo de un cuadro grave de la enfermedad y no como tratamiento contra ella. Es por esto lo que se ha convertido en una necesidad el desarrollo de un fármaco antiviral contra SARS-CoV-2 (Severe Acute Respiratory Syndrome Coronavirus 2), sin embargo, el desarrollo de un fármaco de in novo es un procedimiento muy largo y costoso. Considerando lo anterior se han desarrollado diversos estudios de reposicionamiento de fármacos, basados en el uso de un fármaco existente con un nuevo fin terapéutico contra el COVID-19.

https://user-images.githubusercontent.com/78750648/130305523-ca975e6a-a075-4694-b2e2-e32cacb0bcfe.mov

![Figura 1  Estructura de Favipiravir-RTP en su forma activa](https://user-images.githubusercontent.com/78750648/130305434-651375f0-fd4f-4aa3-8b71-2434fd5ec6a6.png)

*Figura 1. Estructura de Favipiravir-RTP en su forma activa*

Favipiravir es un profármaco inicialmente utilizado en casos de influenza resistentes al tratamiento convencional. Este es convertido a su forma activa Favipiravir-RTP tal como se vio anteriormente en la Figura 1, tras una ribosilación y fosforilación intracelular, que inhibe la ARN polimerasa dependiente de ARN (RdRp), tal como se muestra en la Figura 2 mediante competencia con los nucleótidos de purina, previniendo la replicación del genoma viral, así como la formación de nuevos viriones (Esquema 1). El dominio catalítico de la RdRp se encuentra bien conservado entre los virus de ARN, por lo tanto, es posible que este antiviral tenga efecto sobre el sitio catalítico de la RdRp del SARS-CoV-2.

![Figura 2  Estructura de la ARN polimerasa dependiente de ARN (RdRp)](https://user-images.githubusercontent.com/78750648/130305576-ca10e71c-c530-47c2-b5b1-a3be3ef9c9b3.png)

*Figura 2. Estructura de la ARN polimerasa dependiente de ARN (RdRp)*

![Esquema 1  Proceso de inhibición de RdRp por Favipiravir-RTP](https://user-images.githubusercontent.com/78750648/130305619-9e6138c9-8e57-4dcf-999f-1e1cb07d9259.png)

*Esquema 1. Proceso de inhibición de RdRp por Favipiravir-RTP*

El análisis de acoplamiento molecular (molecular docking) permite buscar la mejor conformación y posición de un ligando dentro de un receptor, por ejemplo, una enzima (Saldívar et al. 2016), mediante el estudio de las fuerzas de unión entre ambas estructuras; el acoplamiento molecular se ha convertido en una herramienta esencial para el descubrimiento y reposicionamiento de fármacos (Ferreira et al., 2015). La unión entre un fármaco (F) y su receptor (R) está descrita por la constante de asociación (ecuación 1), siendo ésta una reacción de asociación simple, mientras más alta sea la constante, mayor es la energía liberada en la interacción del receptor y el fármaco, dependiendo de la afinidad de unión del complejo ligando-receptor (Ferreira et al. 2015).

![Ec1](https://user-images.githubusercontent.com/78750648/130305689-88b3e5d2-05cf-4e11-a71e-91fef89c6f49.JPG)

Para poder realizar el acoplamiento molecular es necesario contar con la estructura tridimensional del ligando y del receptor, dichas estructuras pueden ser obtenidas a partir del Protein Data Bank (PDB). En este trabajo se realiza el acoplamiento de Favipiravir, posible fármaco para tratar la enfermedad ocasionada por SARS-CoV-2, a partir de la interacción del sitio activo (residuos D760 y D761) (Poner el VÍDEO residuos)  (Hillen, H. et al. 2020) de la RdRp y el Favipiravir-RTP. 

## **2. Metodología**

### *2.1  Análisis de acoplamiento molecular in silico*

Se realizó el acoplamiento molecular a partir de la estructura cristalina de RdRp obtenida a partir del Protein Data Bank (PDB) con el código 7BW4 y el fármaco Favipiravir-RTP obtenido de PubChem con el CID 5271809. Posteriormente se editaron las moléculas con el programa PyMOL eliminando las estructuras que no se requieren.

Una vez realizada la edición de la proteína y el fármaco a evaluar se procedió a añadir la carga e hidrógenos polares a la RdRp en el programa AutoDock Tools y se convirtió en formato .pdbqt; el Favipiravir-RTP se convirtió al mismo formato. Por último, se introdujeron los comandos correspondientes en símbolo del sistema (cdm) y con ayuda del programa Vina (O. Trott, 2010) se desarrolló el acoplamiento. 

### *2.2 Análisis de la dinámica molecular*

Por medio de la plataforma SwissParam, se obtuvieron los archivos necesarios para realizar la dinámica molecular, para su posterior ejecución empleando Gromacs 2021 GPU mediante la plataforma Google Colab donde se efectuaron los pasos necesarios para el acondicionamiento y subsiguiente análisis de dinámica molecular.

## **3. Resultados y discusión**

### *3.1  Acoplamiento molecular RdRp-Favipiravir*

Los valores de afinidad en el acoplamiento molecular RdRp-Favipiravir van desde -6.4 a -6.9 kcal/mol. Sin embargo, para el análisis de dinámica molecular fue vital observar si los modelos interaccionaban con los residuos D760 y D761 pertenecientes al sitio activo de RdRp, destacando que el modelo nueve con una menor afinidad (Tabla 1) tiene una directa unión con el sitio activo de RdRp (Figura 3).

![Figura 3](https://user-images.githubusercontent.com/78750648/130305972-c45b5320-7f77-45f6-bb52-b5ee9f5fdeb6.png) 

https://user-images.githubusercontent.com/78750648/130306027-c628bf84-5d74-4d88-b787-35cc16e9eb55.mov

*Figura 3. Primer modelo de interacción entre Favipiravir y el sitio activo (residuos D760 y D761) de RpRd con afinidad de -6.9 kcal/mol*

Por otra parte, si bien el primer modelo (Figura 4) no tiene una directa interacción con los residuos de interés cuenta con los mejores valores de afinidad y es posible que dentro del organismo logre bloquear a la RdRp.

![Imagen5](https://user-images.githubusercontent.com/78750648/130305999-0622a3d7-3506-4081-9585-4705bb5b8989.png) 

https://user-images.githubusercontent.com/78750648/130306066-618b5f54-98a6-474f-b5ef-38f0149df7ab.mov

*Figura 4. Noveno modelo de interacción entre Favipiravir y el sitio activo (residuos D760 y D761) de RpRd con afinidad de -6.4 kcal/mol*

| Modelo  | Afinidad (kcal/mol) |
| -| - |
| 1 | -6.9 |
| 2 | -6.9 |
| 3 | -6.8 |
| 4 | -6.7 |
| 5 | -6.7 |
| 6 | -6.7 |
| 7 | -6.5 |
| 8 | -6.5 |
| 9 | -6.4 |


Tabla 1. Afinidad del acoplamiento molecular de RdRp-Favipiravir

### *3.2  Dinámica molecular  RdRp-Favipiravir*

Finalmente, con las estructuras obtenidas en el docking molecular se utilizó el acoplamiento con mayor afinidad (modelo uno) y el de mejor adaptación al dominio catalítico (modelo nueve) logrando los siguientes resultados.

#### *3.2.1  Presión*

Los valores de presión en ambos modelos varían ligeramente, pues tomando en cuenta la media de los datos, el comportamiento es normal, debido a la fluctuación de la presión mientras está corriendo la simulación de la dinámica molecular, no obstante, el primer modelo alcanza un pico mayor de presión, aproximadamente de 180 bar a diferencia del modelo nueve, aproximadamente 120 bar.

![Imagen6](https://user-images.githubusercontent.com/78750648/130306244-9256d202-e80a-4ac7-8c5f-9df1162ddd4f.png) ![Imagen7](https://user-images.githubusercontent.com/78750648/130306245-a0849e19-ca93-4899-be05-472163c6b9f3.png)

*Figura 5. Presión de los modelos uno y nueve del acoplamiento molecular Favipiravir-RTP-RdRp respectivamente*

#### *3.2.2  Densidad*

Para el modelo uno la densidad comienza a ser constante a partir de 〜10 ps con un valor de hasta >1015 kg/m3 mientras que para el modelo nueve es a partir de 〜5 ps y >1015 kg/m3 por lo tanto es posible asegurar que para ambas dinámicas moleculares no se necesitan 100 ps para lograr el equilibro del sistema, sin embargo, mientras haya visitado el espacio-fase durante un mayor tiempo en nuestro sistema será mejor.

![Imagen8](https://user-images.githubusercontent.com/78750648/130306288-f2e2969b-a55e-4a04-8544-806de66e33c7.png) ![Imagen9](https://user-images.githubusercontent.com/78750648/130306290-847d62c9-9a09-46b1-ac76-e3a5ee944481.png)

*Figura 6. Densidad de los modelos uno y nueve del acoplamiento molecular Favipiravir-RTP-RdRp respectivamente*

#### *3.2.3 Raíz de la desviación cuadrática media (RDCM)*

La diferencia entre los resultados de la raíz de la desviación cuadrática media (RDCM) de ambos modelos es notable, pues la estabilidad del primer modelo se nivela a 〜0.175 nm con un pico mayor en 〜0.245 nm y un pico menor en 0.130 nm, siendo la diferencia entre ambos picos de 〜0.115nm; en cambio el último modelo a 〜0.27nm logra estabilidad, con picos de mayor y menor valor, 0.30 nm y 0.21 nm respectivamente, con una diferencia de 0.09 nm, evidenciando que el último modelo es más estable.

![Imagen10](https://user-images.githubusercontent.com/78750648/130306313-522fed4c-0502-41fb-a2f8-614fb12e74fe.png) ![Imagen11](https://user-images.githubusercontent.com/78750648/130306314-2bb6353b-da8f-49d0-8229-588a8c19d58c.png)

*Figura 7. RDCM de los modelos uno y nueve del acoplamiento molecular Favipiravir-RTP-RdRp*

#### *3.2.4  Potencial de energía Lennard-Jones*

Recordando que el potencial de Lennard-Jones (LJ) es para la interacción de dos átomos, el modelo nueve logra su mejor interacción a los 4600 ps con 〜135 kJ/mol mientras el primer modelo la logra a los 340 ps con 〜165 kJ/mol. Por lo anterior es posible decir que las partículas del primer modelo están mayormente unidas porque la distancia entre sus centros es más baja que la del modelo nueve.

![Imagen12](https://user-images.githubusercontent.com/78750648/130306372-9bd9325d-5dbb-44a0-ad65-aefdd350f3e9.png) ![Imagen13](https://user-images.githubusercontent.com/78750648/130306373-d671c51c-cb93-4294-913d-a43bc8032cd0.png)

*Figura 8. Potencial de energía LJ de los modelos uno y nueve del acoplamiento molecular Favipiravir-RTP-RdRp*

#### *3.2.5  Potencial de energía Coulombic (Coul-SR)*

El modelo nueve, tiene el valor más alto de potencial siendo de aproximadamente -640 kJ/mol, es decir, su interacción electrostática es 290 veces más que la del primer modelo, con -350 kJ/mol. Ahora, aunque la interacción del último modelo es mayor, esta interacción no se mantuvo por mucho tiempo, lo contrario al primer modelo, ya que sus interacciones fueron más estables. 

![Imagen14](https://user-images.githubusercontent.com/78750648/130306491-b6f67259-f833-4909-88c1-b6da9bdbc682.png) ![Imagen15](https://user-images.githubusercontent.com/78750648/130306494-33129926-b3d6-41ca-a321-ff1033a97eb2.png)

*Figura 9. Potencial de energía Coul-SR de los modelos uno y nueve del acoplamiento molecular Favipiravir-RTP-RdRp*

Comparando todas las interacciones  entre el primer modelo de acoplamiento y el último podemos observar que, sin importar la diferencia de valores entre los parámetros anteriores, es evidente que el fármaco Favipiravir-RTP tiene interacción con la RdRp. Asimismo, el modelo con menor afinidad en el acoplamiento molecular, demostró tener un mayor potencial de Coul-SR, arrojando que tiene una fuerte interacción electrostática pero por menor tiempo. Por último, el primer modelo presentó valores bajos en las interacciones pero mucho más estables, por lo cual es posible suponer que la inhibición de la RdRp puede lograrse sin problemas.

https://user-images.githubusercontent.com/78750648/130306661-1b7365b4-e190-4bee-abbd-3f399ad8559a.mp4

https://user-images.githubusercontent.com/78750648/130306671-b6a643e9-2e58-4df7-81ce-569f9dd021e8.mp4

## **4. Futuras líneas de investigación**

### *4.1  Desarrollo del estudio pre-clínico*

Los fármacos evaluados han pasado por las etapas de desarrollo para su aplicación clínica, lo anterior otorga conocimientos en cuestión de seguridad, farmacodinámica y farmacocinética, reduciendo el riesgo de aplicación para reposicionamiento (Carranza, A. S. et al. 2020).

El reposicionamiento de Favipiravir-RTP como tratamiento contra la COVID-19 ha sido estudiado por diversos científicos, destacando la investigación de la Red Argentina Pública de Evaluación de Tecnologías Sanitarias concluyendo que dicho fármaco lograría unirse a dominios de polimerasa conservados, sin embargo no recomiendan ampliamente el uso de Favipiravir por cual proponemos los siguientes estudios:

#### *4.1.1  In vitro*

Por medio de cultivos de células Vero E6 en DMEM con suero bovino fetal, infectados con SARS-CoV-2 a fin de observar en ensayos de placa estándar si el comportamiento fármaco-patógeno in silico es el adecuado.

![Imagen16](https://user-images.githubusercontent.com/78750648/130306878-0decd220-b7ad-4278-ab8e-20a239ccb66c.png)

*Esquema 2. Diseño del estudio in vitro para reposicionamiento de Favipiravir-RTP*

#### *4.1.2  In vivo*

Utilizar modelos animales de rata blanca o macaco rhesus, de acuerdo con los recursos del laboratorio, para la infección por SARS-CoV-2 con el objetivo de lograr conocer la farmacodinámica del antiviral, su efecto terapéutico, así como de sus posibles efectos secundarios. Es fundamental asignar todos los animales aleatoriamente en grupos e inocular a diversas dosis, sin exceder la dosis máxima tolerada.

![Imagen17](https://user-images.githubusercontent.com/78750648/130306901-5c6b8a95-a192-4796-9681-ee10d7c7a6cb.png)

*Esquema 3. Diseño del estudio in vivo para reposicionamiento de Favipiravir-RTP*

#### *4.1.3  Clínico*

Se recomienda realizar un estudio paralelo, doble ciego, aleatorizado, controlado con placebo (Esquema 4) para personas SARS-CoV-2 positivo con criterios de exclusión de embarazadas y coinfección con influenza. Utilizando distintas dosis (no mayores a la máxima tolerada), así como un placebo con cuidados médicos convencionalmente utilizados.

![Imagen18](https://user-images.githubusercontent.com/78750648/130306927-36a11a7a-3dfe-45ee-87e2-1090e8827fa6.png)

*Esquema 4. Diseño del estudio clínico para reposicionamiento de Favipiravir-RTP*

Es importante evaluar la eficacia y seguridad, así como seleccionar la dosis óptima de Favipiravir como adyuvante para la recuperación de pacientes COVID-19 positivos.

## **5. Conclusiones**

Los análisis in silico sobre la interacción del Favipiravir en su forma activa Favipiravir-RTP sobre la RdRp presente en SARS-CoV-2 permiten intuir que este fármaco tiene potencial antiviral, y por ende, podría funcionar como tratamiento para la Covid-19. Es necesario la realización de estudios in vitro, in vivo y preclínicos que cumplan con las características mencionadas en los diferentes diseños de estudios mencionados en el presente artículo para poder recomendar y aplicar dicho fármaco como un tratamiento eficaz, ya sea de forma individual o en combinación con algún otro medicamento y poder cumplir con el objetivo de salud y bienestar de la Age.

## **6. Bibliografía**

1.	CONACYT-CentroGeo-GeoInt-DataLab (2020) Covid-19 México. https://datos.covid-19.conacyt.mx/#COMNac
2.	Mathieu, E., Ritchie, H., Ortiz-Ospina, E. et al. A global database of COVID-19 vaccinations. Nat Hum Behav (2021)
3.	Saldívar, F., Prieto, F. & Medina, J.L.(2016) Descubrimiento y desarrollo de fármacos: un enfoque computacional. Educación Química 28, 51-58.
4.	Ferreira, L., dos Santos, R.N, Oliva, G. & Andricopulo, A. (2015) Molecuar Docking and Structure-Based Drug Design Strategies. Molecules, 20, 13384-13421 
5.	Hillen, H. S., Kokic, G., Farnung, L., Dienemann, C., Tegunov, D., & Cramer, P. (2020). Structure of replicating SARS-CoV-2 polymerase. Nature, 584(7819), 154-156.
6.	O. Trott, A. J. Olson,                                        AutoDock Vina: improving the speed and accuracy of docking with a new scoring function, efficient optimization and       multithreading, Journal of Computational Chemistry 31 (2010) 455-461 http://doi.org/10.1002/jcc.21334
7.	Carranza-Aranda, A. S., Segura-Cabrera, A., Cárdenas-Vargas, A., & Herrera-Rodríguez, S. E. (2020). Reposicionamiento de fármacos identificados por métodos computacionales (SVBS), para su uso como terapias contra el cáncer. Salud Jalisco, 7(1), 48-57.
8.	Carrasco, G., García, D.E. & Tortosa, F. (2020) Uso de Favipiravir en COVID-19. Red Argentina Pública de Evaluación de Tecnologías Sanitarias. https://docs.bvsalud.org/biblioref/2020/10/1123245/favipiravir2-1.pdf 
9.	Furuta, Y., Komeno, T., & Nakamura, T. (2017). Favipiravir (T-705), a broad spectrum inhibitor of viral RNA polymerase. Proceedings of the Japan Academy, Series B, 93(7), 449-463.
10.	Londhe, A. M., Gadhe, C. G., Lim, S. M., & Pae, A. N. (2019). Investigation of molecular details of Keap1-Nrf2 inhibitors using molecular dynamics and umbrella sampling techniques. Molecules, 24(22), 4085.
