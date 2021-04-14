<h1><b><p align=center> PDIH: Seminario 2</p></b></h1>

## **1. Introducción a códigos QR**

&nbsp;&nbsp;&nbsp;&nbsp;Con la información adquirida del seminario he escrito un programilla para crear códigos QR y otro para leerlos. El trabajo que escogí de la asignatura se basa en esto, en los códigos QR, y me ha parecido muy interesante poder verlo en este seminario. Claramente me inspiraré en esto para hacer el trabajo.

&nbsp;&nbsp;&nbsp;&nbsp;A continuación procederé a explicar las funcionalidades de los códigos implementados. Decidí hacerlo en *Python*, ya que es un lenguaje que controlo, y *R* aún no lo he estudiado. Tanto los códigos como las imágenes QR están dentro de la carpeta S-qr, por si quisiera comprobar el funcionamiento.

## **2. QR Creator**

&nbsp;&nbsp;&nbsp;&nbsp;El programa, escrito en el archivo *qr.py* contiene el siguiente código:

```python
import qrcode

print("Bienvenido! Indique la frase o enlace que desea que se añada al código")
contenido = input()

print("Ahora especifique el nombre del archivo")
nombre = input()

nombre = nombre+".png"

img = qrcode.make(contenido)
img.save(nombre)
```

&nbsp;&nbsp;&nbsp;&nbsp;Como se ve, es un código muy sencillo. Primero se nos pide el enlace o frase que queremos meter dentro del código QR. Después se debe especificar el nombre del archivo, y a este se le añade *.png* al final. Finalmente se crea el código y se guarda con el nombre especificado. A continuación hago un ejemplo.

![1](https://github.com/jcpicco/pdih/blob/main/S-qr/capturas/1.png "1")

&nbsp;&nbsp;&nbsp;&nbsp;Aquí he puesto un enlace a la famosa canción de Rick Astley "Never Gonna Give You Up", y lo he guardado como *rickroll.png".

![2](https://github.com/jcpicco/pdih/blob/main/S-qr/capturas/2.png "2")

## **3. QR Reader**

&nbsp;&nbsp;&nbsp;&nbsp;Este programa, escrito en el archivo *lectorqr.py* es un poco más complejo. Utilizamos la librería OpenCV y la librería Sys. El código es el siguiente:

```python
import cv2
import sys

filename = sys.argv[1]
img = cv2.imread(filename)
detector = cv2.QRCodeDetector()

data, bbox, straight_qrcode = detector.detectAndDecode(img)

if bbox is not None:
    print(f"Datos del código QR:\n{data}")
```

&nbsp;&nbsp;&nbsp;&nbsp;Primero se debe de especificar el nombre del archivo previamente como argumento del programa de Python. Luego lees el archivo con OpenCV e inicializas el detector de OpenCV para poder utilizarlo.

&nbsp;&nbsp;&nbsp;&nbsp;Finalmente se usa la función de OpenCV *detectAndDecode(img)*, que te devuelve en 3 variables distintas. *data* te da la información de dentro del código, *bbox* en resumidas cuentas te dice si está vacío o no el código QR, y *straight_qrcode* te dice en forma de matriz las celdas pintadas del código QR. Comprobamos que bbox no esté vacío y te da los datos del código.

![3](https://github.com/jcpicco/pdih/blob/main/S-qr/capturas/3.png "3")