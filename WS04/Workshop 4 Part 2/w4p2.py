import pyautogui as gui
import time

time.sleep(5)

with open('w4p2.txt', 'r') as tst:
    time.sleep(1)
    tst = tst.readlines()
    for i in range(0, len(tst), 1):
        print(tst[i])
        gui.typewrite(tst[i])

print('Autp data input completed.')
