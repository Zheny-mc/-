from tkinter import *
from tkinter.ttk import Combobox

def KeyClicked():
    print('key')

def OkClicked():
    print('Ok')

def CanelClicked():
    print('Canel')

def HelpClicked():
    print('help')

WIDTH = 660
HEIGHT = 175
FONT_SIZE = 12

window = Tk()
window.title("Zipper")
window.geometry(str(WIDTH)+"x"+str(HEIGHT))
window.resizable(False, False)

#виджеты
lbl_name = Label(window, text="Имя архива", font=("Arial Bold", FONT_SIZE))
txt_name = Entry(window, width=WIDTH)

lbl_compression = Label(window, text="Метод сжатия:", font=("Arial Bold", FONT_SIZE))
combo_compression = Combobox(window, font=("Arial Bold", FONT_SIZE))  
combo_compression['values'] = ("Слабое", "Среднее", "Сильное")  
combo_compression.current(1) 

lbl_division = Label(window, text="Разбить на тома размером(МБ):", font=("Arial Bold", FONT_SIZE))
combo_division = Combobox(window, font=("Arial Bold", FONT_SIZE))  
combo_division['values'] = (1,2,3,4,5,6,7,8,9,10)  
combo_division.current(1) 

lbl_paramArchiving = Label(window, text="Праметры архивации:", font=("Arial Bold", FONT_SIZE))
rbt1_paramArchiving = Radiobutton(window, text='Удалить файлы после архивации', font=("Arial Bold", FONT_SIZE))
rbt2_paramArchiving = Radiobutton(window, text='Протестировать файла после архивации', font=("Arial Bold", FONT_SIZE))

btn_installKey = Button(window, text="Установить пароль...", font=("Arial Bold", FONT_SIZE), command=KeyClicked)
btn_ok = Button(window, text="ОК", font=("Arial Bold", FONT_SIZE), command=OkClicked)
btn_canel = Button(window, text="Отмена", font=("Arial Bold", FONT_SIZE), command=CanelClicked)
btn_help = Button(window, text="Справка", font=("Arial Bold", FONT_SIZE), command=HelpClicked)

#отображение виджитов
lbl_name.place(anchor="nw")
txt_name.place(x=0, y=20, width=WIDTH)
lbl_compression.place(x=0, y=45)
combo_compression.place(x=5, y=65)

lbl_division.place(x=0, y=85)
combo_division.place(x=5, y=105)

lbl_paramArchiving.place(x=WIDTH*0.42, y=45)
rbt1_paramArchiving.place(x=WIDTH*0.42, y=65)
rbt2_paramArchiving.place(x=WIDTH*0.42, y=85)

btn_installKey.place(x=5, y=HEIGHT*0.78)
btn_ok.place(x=WIDTH*(0.6), y=HEIGHT*0.78, width=80)
btn_canel.place(x=WIDTH*(0.6)+90, y=HEIGHT*0.78, width=80)
btn_help.place(x=WIDTH*(0.6)+180, y=HEIGHT*0.78, width=80)

#зацикливание
window.mainloop()
