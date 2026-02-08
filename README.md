Módulo de secado y acondicionamiento de filamento PET

Trabajo Final – Diplomatura en Robótica Educativa

Descripción general del proyecto

Este proyecto consiste en el desarrollo de un módulo de secado y acondicionamiento de filamento PET para impresión 3D, orientado a contextos educativos maker.
El sistema controla variables ambientales críticas (temperatura y humedad) dentro de un gabinete reciclado (chasis de CPU), con el objetivo de mejorar la calidad del filamento reutilizado y, al mismo tiempo, favorecer la comprensión de sistemas de control embebidos.

El diseño prioriza:

Reutilización de materiales

Bajo consumo energético

Simplicidad técnica

Claridad pedagógica

Objetivos
Objetivo general

Diseñar y construir un sistema automatizado que permita secar y acondicionar filamento PET mediante el control de temperatura y humedad.

Objetivos específicos

Implementar sensores de temperatura y humedad.

Controlar calefacción y ventilación mediante lógica ON/OFF.

Visualizar variables y estados del sistema en una pantalla OLED.

Integrar el proyecto en una propuesta educativa interdisciplinaria.

Arquitectura del sistema

El sistema se compone de:

Zona inferior: carretel de filamento PET

Zona superior: electrónica de control, sensores, calefacción y ventilación

Panel de monitoreo: pantalla OLED integrada

El control se realiza mediante una placa ESP32, que gestiona sensores, actuadores y visualización de datos.

Plataforma tecnológica

Plataforma de hardware: ESP32

Lenguaje de programación: C++ (Arduino Framework)

Tipo de programación: Texto

Entorno de desarrollo: Arduino IDE

Sistema operativo: Independiente del SO (firmware embebido)

Este entorno fue elegido por su amplia documentación, estabilidad y uso extendido en contextos educativos.

Sensores y actuadores
Sensores

DS18B20: medición precisa de temperatura del filamento PET.

DHT22: medición de temperatura ambiente y humedad relativa.

Actuadores

Resistencia calefactora: elevación controlada de temperatura.

Ventilador 12V: circulación de aire y reducción de humedad.

Relé: control de potencia del sistema de calefacción.

Buzzer: alerta por temperatura excesiva.

LED: indicador visual de estado.

Lógica de control

El sistema utiliza una lógica de control ON/OFF, basada en condiciones simples:

Si la temperatura del filamento es menor al valor mínimo → se activa la calefacción.

Si la temperatura supera el máximo seguro → se apaga la calefacción y se activa una alarma.

Si la humedad es elevada → se activa el ventilador.

Las variables y estados se muestran en tiempo real en la pantalla OLED.

Este enfoque fue elegido por:

Su claridad pedagógica.

Su confiabilidad.

Su adecuación a contextos formativos iniciales.

Sistema de monitoreo (OLED)

La pantalla OLED I2C 128×64 integrada cumple un rol central:

Muestra temperaturas, humedad y estados de los actuadores.

Permite operar el sistema sin necesidad de una computadora.

Facilita la observación directa del funcionamiento del algoritmo.

Esto convierte al módulo en un sistema autónomo y didáctico.

Enfoque pedagógico

La propuesta está diseñada para niveles:

Educación secundaria técnica

Formación docente

Espacios maker y talleres educativos

Contenidos abordados:

Electrónica básica

Programación de sistemas embebidos

Sensores y actuadores

Control ambiental

Sustentabilidad y reciclaje

El proyecto integra saberes de tecnología, física, electrónica y educación ambiental, promoviendo un enfoque interdisciplinario y práctico.
Código fuente

El código fue desarrollado en Arduino IDE y se encuentra disponible para su consulta y reutilización en el repositorio asociado a este proyecto.

El programa implementa:

Lectura de sensores

Control de actuadores

Visualización en pantalla OLED

Gestión de alarmas

Escalabilidad

El sistema puede ampliarse incorporando:

Control PID

Registro de datos (data logging)

Conectividad WiFi

Interfaz web o app

Control remoto y notificaciones

Conclusión

Este proyecto demuestra que es posible desarrollar soluciones técnicas funcionales, eficientes y sostenibles, integrando robótica, programación y educación ambiental.
El proceso de diseño y construcción permitió articular saberes técnicos con una mirada pedagógica, fortaleciendo el aprendizaje significativo a través del hacer.
