from tkinter import *

WIDTH = 480
HEIGHT = 640
FONT_SIZE = 12

window = Tk()
window.title("Zipper")
window.geometry(str(WIDTH)+"x"+str(HEIGHT))
#window.resizable(False, False)

lbl_name = Label(window, text="Имя архива", font=("Arial Bold", FONT_SIZE))
txt_name = Entry(window)
lbl_compression = Label(window, text="Метод сжатия:", font=("Arial Bold", FONT_SIZE))
lbl_update = Label(window, text="Метод обновления:", font=("Arial Bold", FONT_SIZE))
lbl_paramArchiving = Label(window, text="Праметры архивации:", font=("Arial Bold", FONT_SIZE))
btn_installKey = Button(window, text="Установить пароль...", font=("Arial Bold", FONT_SIZE))
btn_ok = Button(window, text="ОК", font=("Arial Bold", FONT_SIZE))
btn_canel = Button(window, text="Отмена", font=("Arial Bold", FONT_SIZE))
btn_help = Button(window, text="Справка", font=("Arial Bold", FONT_SIZE))

lbl_name.place(anchor="nw")
txt_name.place(x=0, y=20, width=WIDTH)
lbl_compression.place(x=0, y=45)
lbl_update.place(x=240, y=45)
lbl_paramArchiving.place(x=240, y=65)
btn_installKey.place(x=240, y=85)
btn_ok.place(x=WIDTH*(0.45), y=HEIGHT*0.93, width=80)
btn_canel.place(x=WIDTH*(0.45)+90, y=HEIGHT*0.93, width=80)
btn_help.place(x=WIDTH*(0.45)+180, y=HEIGHT*0.93, width=80)

window.mainloop()
