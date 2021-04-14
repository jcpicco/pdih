from tkinter import *
from tkinter import filedialog
from tkinter import messagebox
import qrcode

def showImage(nombre):
    newWindow = Toplevel(top)
    newWindow.title("QR creado!")
    img = PhotoImage(file=nombre)
    label1 = Label(newWindow, text="¡Código QR creado!")
    label2 = Label(newWindow, image=img)
    label2.image = img
    label1.pack()
    label2.pack(side="bottom",fill="both",expand="yes")
    
def browse_button():
    global folder_path
    filename = filedialog.askdirectory()
    folder_path.set(filename)
    print(filename)

def submit():
    contenido = E1.get()
    dir = folder_path.get()
    nombre = dir+"/"+E2.get()+".png"
    img = qrcode.make(contenido)
    img.save(nombre)
    showImage(nombre)

top = Tk()
top.title("QRCreator")
top.resizable(False, False)
top.geometry("300x300")
folder_path = StringVar()

title = Label(top, text="QRCreator", font=("Liberation Serif",45))
title.pack()
title.place(relx=0.5, rely=0.1, anchor=CENTER)

L1 = Label(top,text="Contenido QR:")
L1.pack(side=LEFT)
L1.place(x=10, y=65)
E1 = Entry(top, bd=5)
E1.pack(side=RIGHT)
E1.place(x=110, y=60)

L2 = Label(top,text="Nombre QR:")
L2.pack(side=LEFT)
L2.place(x=10, y=105)
E2 = Entry(top, bd=5)
E2.pack(side=RIGHT)
E2.place(x=110, y=100)

Label(master=top, textvariable=folder_path)
Button(text="Elegir directorio", command=browse_button).pack(side=LEFT)

B2 = Button(top, text = "Crear QR", command = submit)
B2.pack()
B2.place(relx=0.5, rely=0.7, anchor=CENTER)

top.mainloop()