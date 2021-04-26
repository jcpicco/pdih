<h1><b><p align=center> PDIH: Trabajo Códigos QR</p></b></h1>

## **1. Introducción a los códigos QR**

&nbsp;&nbsp;&nbsp;&nbsp;Diariamente, y más en la situación sanitaria actual, los códigos QR están más presentes que nunca. Día tras día nos vemos enfrente de alguno y de esto es de lo que voy a hablar hoy.

&nbsp;&nbsp;&nbsp;&nbsp;Un código QR en muy resumidas cuentas es un módulo para almacenar información. Es la evolución del código de barras. Tiene una velocidad de respuesta muy rápida, y de ahí vienen las siglas QR, de Quick Response.

![1](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/1.png "1")

&nbsp;&nbsp;&nbsp;&nbsp;Su estructura es una matriz bidimensional de dos colores. Hay 10 versiones distintas en función de la cantidad de datos que deba almacenar, que va de la versión 1 de 21x21, hasta la versión 10 de 177x177. Uno de sus fuertes también es que admite cierta personalización, como redondeado de los módulos, colores distintos que no sean blanco y negro, etc. Como norma fundamental los colores que se escojan deben de estar lo suficientemente contrastados para que funcione.

## **2. Historia de los códigos QR**

&nbsp;&nbsp;&nbsp;&nbsp;Los códigos QR fueron desarrollados en 1994, hace ya más de 25 años, por una multinacional japonesa llamada Denso Wave, la cual es subsidiaria de Toyota. En sus inicios se usó para registrar repuestos en el ámbito de la automoción, ya que esta empresa se dedicaba a eso. Masahiro Hara es el ingeniero jefe de la empresa, y el que lo desarrolló.

![2](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/2.png "2")

&nbsp;&nbsp;&nbsp;&nbsp;Masahiro se inspiró en el juego de mesa Igo, el cual es una especie de Reversi en el que para capturar las fichas de tu adversario tienes que rodearlas de tu color. Un tablero de Igo guarda bastantes similitudes con los códigos QR visto desde arriba, y durante un almuerzo se le ocurrió. Es en estos últimos años cuando se ha popularizado más con la llegada de los lectores QR para smartphones.

![3](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/3.png "3")

## **3. Futuro de los códigos QR**

&nbsp;&nbsp;&nbsp;&nbsp;Actualmente son usados en la hostelería y el comercio sobre todo, para tener la carta al alcance del usuario sin necesidad de una carta física, lo que es mucho más higiénico en las circunstancias actuales. Ahora hace relativamente poco se está usando como plataforma para recibir y enviar pagos.

&nbsp;&nbsp;&nbsp;&nbsp;En China AliPay es la app por excelencia para pagos QR, la cual supera los mil millones de usuarios. En este país se lleva usando el pago QR desde el 2015, y ya en ese momento el 35% de las personas lo usaban. Actualmente el porcentaje se ha disparado a casi un 80%. En España Bizum es el líder de los pagos QR actualmente.

![4](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/4.png "4")

&nbsp;&nbsp;&nbsp;&nbsp;Otras utilidades son la información turística, la recogida de pedidos o la validación de billetes para autobuses, trenes, aviones, etc.


## **4. Programa: QRCreator**

&nbsp;&nbsp;&nbsp;&nbsp;Este programa es el mismo prácticamente del seminario, pero le he añadido algunas funciones más y una interfaz gráfica MUY sencilla. He utilizado la librería *tkinter* para la interfaz y la librería *qrcode* para el generador.

&nbsp;&nbsp;&nbsp;&nbsp;He creado 3 funciones para facilitar la comprensión del código y son las siguientes:

1. **showImage(nombre):** Esta función tiene la funcionalidad de mostrar tras la ejecución del programa una preview del código QR creado.

2. **browse_button():** Esto ejecuta el diálogo de selección de carpeta en donde guardar el archivo.

3. **submit():** Básicamente lo que esta función hace es encapsular toda la creación del código QR y finalmente llamar a *showImage()* para que se muestre la imagen creada.

![5](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/5.png "5")

&nbsp;&nbsp;&nbsp;&nbsp;Aquí vemos la interfaz. Tenemos dos casillas: en una ponemos el contenido del código QR, en la de abajo ponemos el nombre del archivo y luego inmediatamente tenemos el botón para escoger el directorio donde se va a guardar. Finalmente le das a "Crear QR", se crea y te muestra lo que ha creado.

![6](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/6.png "6")