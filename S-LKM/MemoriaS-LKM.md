<h1><b><p align=center> PDIH: Seminario LKM</p></b></h1>

## **1. Introducción a LKM**

&nbsp;&nbsp;&nbsp;&nbsp;LKM es un mecanismo para añadir código extra al kernel de Linux, o eliminarlo, en tiempo de ejecución. Sirve para dar soporte a nuevos periféricos y sistemas de archivos. Sirve como vía de comunicación entre el Kernel y el Hardware, como lo llamado Software de controlador de dispositivo. Los LKM se cargan en tiempo de ejecución, pero no se ejecutan en el espacio de usuario, ya que son parte del Kernel.

&nbsp;&nbsp;&nbsp;&nbsp;En esta práctica añadiremos un módulo de prueba sacado de GitHub para probar su funcionamiento y cómo se acopla correctamente.

## **1. Pasos seguidos**

&nbsp;&nbsp;&nbsp;&nbsp;Primeramente comprobé que las cabeceras de Linux estaban actualizadas e instaladas para desarrollar LKMs.

```shell
sudo apt-get update
sudo apt-cache search linux-headers-$(uname -r)
sudo apt-get install linux-headers-$(uname -r)
```

&nbsp;&nbsp;&nbsp;&nbsp;No tuve que instalar nada nuevo, ya que estaba todo correctamente actualizado. Seguidamente descargué un el código *hello.c* de [este GitHub](https://github.com/derekmolloy/exploringBB/tree/master/extras/kernel/), y lo cambié un poco para comprobar que funciona. El código actualizado puedes encontrarlo [aquí](https://github.com/derekmolloy/exploringBB/tree/master/extras/kernel/).

&nbsp;&nbsp;&nbsp;&nbsp;Tras esto usé un *Makefile* para compilarlo, cuyo código es muy simple:

```makefile
obj-m+=hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
```

&nbsp;&nbsp;&nbsp;&nbsp;He seguido las siguientes instrucciones:

![1](https://github.com/jcpicco/pdih/blob/main/S-LKM/capturas/1.png "1")

&nbsp;&nbsp;&nbsp;&nbsp;He cargado el módulo con *insmod*, y checkeado si se había cargado correctamente con *modinfo*.

![2](https://github.com/jcpicco/pdih/blob/main/S-LKM/capturas/2.png "2")

&nbsp;&nbsp;&nbsp;&nbsp;Tras asegurarme de ello solicité información sobre el módulo que acababa de añadir con *modinfo*. Te da información como el nombre del archivo, su versión, su descripción, su autor, su licencia, la versión del Kernel, etc. Se puede observar que he cambiado ligeramente algunos de los datos.

![3](https://github.com/jcpicco/pdih/blob/main/S-LKM/capturas/3.png "3")

&nbsp;&nbsp;&nbsp;&nbsp;Finalmente he eliminado el Kkernel con *rmmod* y he revisado el registro del log del Kernel que se almacena en la carpeta */var/log* (con la instrucción *tail -f kern.log*).