# Prototipo de bajo costo en plataforma arduino para la toma de temperatura corporal

## Manual de uso

<img src="https://user-images.githubusercontent.com/111079577/184246113-ddf55de2-5dc9-43aa-a57b-b8fbc21639b5.png"/>

## Componentes del sistema

- Arduino NANO: Es el la placa del sistema que se encarga de la interconexión de todos los componentes del sistema así como de recibir los datos, interpretarlos y desplegarlos en la pantalla.

- Termómetro infrarrojo digital: Se utilizó un termómetro MLX90614, el cual envía señales digitales a partir de la temperatura corporal con una precisión de 0.02˚C siempre que se trabaje con temperaturas entre 0˚C y 50˚C.

- Pantalla LCD 16x2: La pantalla LCD 1602A es la que depliega los valores de temperatura y le indica al usuario si presenta o no una temperatura corporal normal.

- Buzzer: El buzzer indica de manera auditiva si la temperatura del usuario es mayor que la normal para una persona saludable.

## Diagrama eléctrico

El dispositivo se implementó utilizando un arduino NANO

<img src="https://user-images.githubusercontent.com/111079577/184243457-439eb978-cc31-4dd1-b951-ce9ff9db84ee.jpg"/>
