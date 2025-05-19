from time import sleep
from datetime import datetime
import os

class base:

    DATA_NAMES = []
    DATA_CATS = []
    DATA_PRICES = []
    DATA_DATES = []
    DATA_TYPES = []

    def addData(name, type, cat, price, date):
        print('Adding new data:',name,'('+cat+')', '-', price, date, '('+type+')')

        base.DATA_NAMES.append(name)
        if cat not in base.DATA_CATS: base.DATA_CATS.append(cat)
        base.DATA_PRICES.append(price)
        base.DATA_DATES.append(date)
        base.DATA_TYPES.append(type)

        sleep(5)
        os.system('cls')
    
    def show():
        plus = 0
        minus = 0
        for i in range(len(base.DATA_NAMES)): 
            if base.DATA_TYPES[i] == '+': plus += int(base.DATA_PRICES[i])
            else: minus += int(base.DATA_PRICES[i])
        print('Incomes:', plus)
        print('Outcomes:', minus)

        print()
        print('Current data:')
        count = 1
        for i in range(len(base.DATA_NAMES)):
            info = str(count) + '. ' + base.DATA_NAMES[i] + ' ('+base.DATA_CATS[i]+')' + ' - ' + base.DATA_PRICES[i] + ' ' + base.DATA_DATES[i] + ' ('+base.DATA_TYPES[i]+')'
            print(info)
            count += 1
        if len(base.DATA_NAMES) == 0: print('Nothing yet.')

        sleep(3 + len(base.DATA_NAMES))
        os.system('cls')
    
    def analyse():
        if '+' in base.DATA_TYPES and '-' in base.DATA_TYPES:
            plus = 0
            minus = 0
            for i in base.DATA_TYPES:
                if i == '+': plus += 1
                if i == '-': minus += 1
            print('Income and outcome difference:', str(plus) + '/' + str(minus))

        catstr = 'Current categories: '
        for i in range(len(base.DATA_CATS)):
            if i < len(base.DATA_CATS)-1: catstr += base.DATA_CATS[i] + ', '
            else: catstr += base.DATA_CATS[i] + '.'
        print(catstr)

        sleep(5)
        os.system('cls')

while True:
    os.system('cls')
    print('What do you want?')
    print('\'data\' - Add new data.')
    print('\'show\' - Show information.')
    print('\'analyse\' - Analyse everything.')
    prompt = input('> ')
    os.system('cls')
    if prompt == 'data':
        a,b,c,d,e = input('Description: '), input('Type (+/-): '), input('Category: '), input('Price: '), input('Date: '),
        base.addData(a,b,c,d,e)
    if prompt == 'show':
        base.show()
    if prompt == 'analyse':
        base.analyse()
