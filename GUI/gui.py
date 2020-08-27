from tkinter import *
from tkinter.ttk import Combobox

def OkClicked():
    print(txt_name.get())
    print("Создаю архив")
    print("Закрываю программу")

def HelpClicked():
    print('Вызываю помощь')
    print('Закрываю программу')

WIDTH = 640
HEIGHT = 480
FONT_SIZE = 11

window = Tk()
window.title("Zipper")
window.geometry(str(WIDTH)+'x'+str(HEIGHT))
#window.resizable(False, False)

#**************************************************************************
top_frame = Frame(window)
top_frame.pack(fill=X)

lbl_name = Label(top_frame, text="Имя архива")
lbl_name.pack(side=LEFT)

middle_frame_1 = Frame(window)
middle_frame_1.pack(fill=X)

txt_name = Entry(middle_frame_1, text="input")
txt_name.pack(fill=X)
#**************************************************************************

bottom_frame = Frame(window, relief=RAISED, borderwidth=1)
bottom_frame.pack(side=BOTTOM, fill=X)

button_help = Button(bottom_frame, text="Справка", command=HelpClicked)
button_help.pack(side=RIGHT, padx=5, pady=5)

button_canel = Button(bottom_frame, text="Отмена", command=window.destroy)
button_canel.pack(side=RIGHT)

button_ok = Button(bottom_frame, text="Готово", command=OkClicked)
button_ok.pack(side=RIGHT, padx=5, pady=5)
#****************************************************************************





'''
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
'''
#отображение виджитов

#зацикливание
window.mainloop()
