import qrcode

print("Bienvenido! Indique la frase o enlace que desea que se añada al código")
contenido = input()

print("Ahora especifique el nombre del archivo")
nombre = input()

nombre = nombre+".png"

img = qrcode.make(contenido)
img.save(nombre)