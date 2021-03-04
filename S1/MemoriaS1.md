<h1><b><p align=center> PDIH: Seminario 1 (Práctica 0)</p></b></h1>

## **1. Configuración de DOSBox**

&nbsp;&nbsp;&nbsp;&nbsp;Para la correcta configuración he añadido en el archivo *dosbox-0.74-3.conf*, el cual se encuentra en mi carpeta */home/juan/.dosbox/*, el siguiente código en el apartado *[autoexec]*:
```
[autoexec]
# Lines in this section will be run at startup.
# You can put your MOUNT lines here.
mount C /home/juan/Documentos/pdih/S1
keyb sp
path c:/home/juan/Documentos/pdih/S1/bc/BIN/
c:
```
&nbsp;&nbsp;&nbsp;&nbsp;Ahora cuando abro DOSBox se monta automáticamente la carpeta S1, que es de donde trabajaré, se carga el teclado en español, y he especificado la ruta de BC, que es con lo que compilaré los programas.

![1](https://github.com/jcpicco/pdih/blob/main/S1/capturas/1.png "Ventana DOSBox configurada")

## **2. Pruebas de compilación**

&nbsp;&nbsp;&nbsp;&nbsp;El siguiente archivo es *C.BAT*, el cual utilizaremos para compilar nuestros programas de DOSBox:

![2](https://github.com/jcpicco/pdih/blob/main/S1/capturas/2.png "C.BAT")

&nbsp;&nbsp;&nbsp;&nbsp;He cogido el código de *hola.asm* y lo he cambiado para que me repita 7 veces la palabra hola. El código, el cual se encuentra en la carpeta de GitHub (archivo holabucle.asm), es el siguiente:
```x86asm
pila segment stack 'stack'
	dw 100h dup (?)
pila ends
datos segment 'data'
	msg db 'hola$'
datos ends
codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax,datos
		mov ds,ax
		;imprimir N veces una cadena
		mov cx,0
		bucle:
			mov dx,OFFSET msg
			mov ah,9
			int 21h
			;actualizar contador y comprobar condición
			inc cx
			cmp cx,7
			jne bucle
		mov ax, 4C00h
		int 21h
	main ENDP
codigo ends

END main
```
&nbsp;&nbsp;&nbsp;&nbsp;El output es el siguiente:

![3](https://github.com/jcpicco/pdih/blob/main/S1/capturas/2.png "holabucle.asm")

## **3. Ejecutando DOOM con DOSBox**
&nbsp;&nbsp;&nbsp;&nbsp;Sorprendentemente el juego DOOM corre perfectamente en DOSBox dentro de una máquina virtual. He ejecutado el comando *DOOM.BAT*, tras haber descargado de la web el propio juego y se ejecuta perfectamente. Me ha parecido muy interesante que el juego ocupe tan poco.

![4](https://github.com/jcpicco/pdih/blob/main/S1/capturas/2.png "DOOM")