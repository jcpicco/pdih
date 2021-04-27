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

&nbsp;&nbsp;&nbsp;&nbsp;En la carpeta QRCreator de [GitHub](https://github.com/jcpicco/pdih/tree/main/trabajo/QRCreator) se encuentra tanto el archivo fuente como su ejecutable y dos códigos QR creados con el programa.

## **5. App: QReader**

&nbsp;&nbsp;&nbsp;&nbsp;Antes de comenzar la realización de esta práctica no había utilizado nunca Android Studio, por lo que para mí ha sido un trabajo doble: tener que aprender lo básico del programa y crear la app. He seguido el tutorial de [esta web](https://learntodroid.com/how-to-create-a-qr-code-scanner-app-in-android/) para llevar a cabo la realización del lector. Esto me ha servido también para familiarizarme con el entorno.

&nbsp;&nbsp;&nbsp;&nbsp;Para la app he usado las librerías CameraX y ZXing. He usado CameraX para crear una vista previa de la cámara en pantalla y ZXing sirve para crear el lector de códigos QR. Voy a pasar a explicar un poco el código y algunas funciones.

&nbsp;&nbsp;&nbsp;&nbsp;La interfaz alojada en [*QRCodeFoundListener.java*](https://github.com/jcpicco/pdih/blob/main/trabajo/QReader/src/app/src/main/java/com/pdih/qreaderapp/QRCodeFoundListener.java) sirve para tratar los códigos QR en cuanto la cámara los detecta. Más adelante veremos la implementación.

&nbsp;&nbsp;&nbsp;&nbsp;El archivo [*QRCodeImageAnalyzer.java*](https://github.com/jcpicco/pdih/blob/main/trabajo/QReader/src/app/src/main/java/com/pdih/qreaderapp/QRCodeImageAnalyzer.java), no lo voy a explicar mucho, ya que es la implementación del analizador de imágenes con la diferencia de que este usa la interfaz anteriormente usada.

&nbsp;&nbsp;&nbsp;&nbsp;En el archivo [*MainActivity.java*](https://github.com/jcpicco/pdih/blob/main/trabajo/QReader/src/app/src/main/java/com/pdih/qreaderapp/MainActivity.java) hay varias funciones las cuales voy a explicar por encima.

1. **void onCreate(Bundle savedInstanceState):** Esta función hace toda la inicialización de la función y la acción del único de los botones que tiene. Iremos viéndola punto por punto.

```java
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        previewView = findViewById(R.id.activity_main_previewView);

        qrCodeFoundButton = findViewById(R.id.activity_main_qrCodeFoundButton);
        qrCodeFoundButton.setVisibility(View.INVISIBLE);
```

&nbsp;&nbsp;&nbsp;&nbsp;Primero se carga la instancia última de la app y el diseño de la app. Luego con *previewView* inicializamos la vista previa de la cámara, y con *qrCodeFoundButton* incializamos el botón a invisible, ya que no contiene nada.

```java
    qrCodeFoundButton.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            Log.i(MainActivity.class.getSimpleName(), "QR encontrado: " + qrCode);

            if(qrCode.contains("https") || qrCode.contains("http")){
                Intent buscadorWeb = new Intent(Intent.ACTION_VIEW, Uri.parse(qrCode));
                startActivity(buscadorWeb);
            }
            else{
                ClipboardManager clipboard = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
                ClipData clip = ClipData.newPlainText("QR",qrCode);
                clipboard.setPrimaryClip(clip);

                WebView webView = new WebView(getApplicationContext());
                webView.setWebViewClient(new WebViewClient());

                Toast.makeText(getApplicationContext(), qrCode+"\n"+"[COPIADO]", Toast.LENGTH_SHORT).show();
            }
        }    
    });
```

&nbsp;&nbsp;&nbsp;&nbsp;Se sobreescribe el funcionamiento del botón: en cuanto se pulse si el código QR contiene "http" o "https" se entiende que es un enlace y se redirige a la página web. En cambio si no contiene esas cadenas de texto se procede a mostrar una notificación Toast con el contenido, y este se copia al portapapeles.

```java
    cameraProviderFuture = ProcessCameraProvider.getInstance(this);
    requestCamera();
    }
```

&nbsp;&nbsp;&nbsp;&nbsp;Finalmente se inicializa el proveedor de cámara que será CameraX, y se piden los permisos de la cámara en el dispositivo.

2. **void requestCamera():** Función que simplemente pide los permisos necesarios para iniciar la cámara.

3. **void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults):** Simplemente hace la acción de si se aceptan los permisos o no. Si se aceptan se inicia la cámara y si se denegan se muestra una notificación Toast avisando que los permisos se han denegado.

4. **void startCamera():** Inicia la cámara del dispositivo.

5. **void bindCameraPreview(@NonNull ProcessCameraProvider cameraProvider):** Inicia la Preview de la cámara. Requiere que la cámara se esté mostrando en la parte trasera y no en la delantera.

```java
imageAnalysis.setAnalyzer(ContextCompat.getMainExecutor(this), new QRCodeImageAnalyzer(new QRCodeFoundListener() {
        @Override
        public void onQRCodeFound(String _qrCode) {
            qrCode = _qrCode;
            qrCodeFoundButton.setVisibility(View.VISIBLE);
            time = new Date().getTime();
        }

        @Override
        public void qrCodeNotFound() {
            time2 = new Date().getTime() - time;
            if(time2 > 2000) {
                qrCodeFoundButton.setVisibility(View.INVISIBLE);
            }
        }
    }));

    Camera camera = cameraProvider.bindToLifecycle((LifecycleOwner)this, cameraSelector, imageAnalysis, preview);
    }
}
```

&nbsp;&nbsp;&nbsp;&nbsp;Aquí se define la acción cuando encontramos un código QR y cuando no. Tuve un problema y es que el botón parpadeaba, así que le hice un pequeño arreglo para que eso no ocurra.

&nbsp;&nbsp;&nbsp;&nbsp;La función *void onQRCodeFound(String _qrCode)* cuando encuentra un código QR el botón lo muestra y guarda el momento exacto de cuando se ha mostrado. En cuanto se deja de detectar public *void qrCodeNotFound()* comprueba que hayan pasado más de 3 segundos. Si han pasado el botón desaparece, y si aún no han pasado se mantiene.

&nbsp;&nbsp;&nbsp;&nbsp;Fuera de la función se inicia la preview virtual de la cámara para realizar pruebas. Aquí dejo unas capturas de la interfaz de la aplicación:

![7](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/7.png "7")

![8](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/8.png "8")

![9](https://github.com/jcpicco/pdih/blob/main/trabajo/capturas/9.png "9")

&nbsp;&nbsp;&nbsp;&nbsp;En la carpeta QReader de [GitHub](https://github.com/jcpicco/pdih/tree/main/trabajo/QReader) se encuentra tanto el código completo como su archivo .apk para instalarlo.

## **6. Demostración**

&nbsp;&nbsp;&nbsp;&nbsp;La demostración la he hecho en un vídeo, el cual puedes ver en YouTube clickando en [este enlace](https://www.youtube.com/watch?v=pyE2zsx358k), o en [GitHub](https://github.com/jcpicco/pdih/tree/main/trabajo/demo-creator-reader.mp4), ya que lo he subido allí también.

## **7. Bibliografía**

- https://es.wikipedia.org/wiki/C%C3%B3digo_QR
- https://www.unitag.io/es/qrcode/what-is-a-qrcode
- https://learntodroid.com/how-to-create-a-qr-code-scanner-app-in-android/
- https://github.com/learntodroid/AndroidQRCodeScanner
- https://www.nippon.com/es/news/fnn20191214001/
- https://es.mobiletransaction.org/pago-con-codigo-qr-en-espana/
- https://www.xataka.com/empresas-y-economia/asi-como-china-esta-dejando-obsoletas-a-tarjetas-credito-1
- https://es.wikipedia.org/wiki/Denso_Corporation
- https://pypi.org/project/qrcode/
- https://docs.python.org/3/library/tkinter.html
- https://likegeeks.com/es/ejemplos-de-la-gui-de-python/
