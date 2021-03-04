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