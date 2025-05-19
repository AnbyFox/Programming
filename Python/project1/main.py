from time import sleep
from random import randint
import os

class game:

    CUR_LOCATION = 'Field'
    LOCATIONS = ['Field', 'Road', 'Abandoned Allay', 'Flying Islands']

    def setLocation():
        print('Where would you like to go?')
        print('1 > Road')
        print('2 > Abandoned Allay')
        print('3 > Flying Islands')
        prompt = input('> ')
        if prompt == '':
            loclevel = randint(1,3)
        else:
            loclevel = int(prompt)

        if loclevel > 3: loclevel = 3
        if loclevel < 1: loclevel = 1

        game.CUR_LOCATION = game.LOCATIONS[loclevel]
        print('')
        print('Your choice: ' + game.CUR_LOCATION)
        print('')

    def encounterEnemy(isBoss = False):
        mult = round((game.LEVEL / 5)) + 1
        if game.CUR_LOCATION == 'Road': level = 1
        elif game.CUR_LOCATION == 'Abandoned Allay': level = 2
        elif game.CUR_LOCATION == 'Flying Islands': level = 3
        else: level = 1

        if isBoss: level, mult = 10, 3

        game.setEnemy(level, mult)
        sleep(2)
        game.battle()

    NAME = 'Player' + str(randint(1,1000))
    CLASS, DMG, DEF, HP, LEVEL, EXP = 'Assasin', 1, 1, 1, 1, 0
    ECLASS, EDMG, EDEF, EHP = 'Droid', 1, 1, 1
    
    INVENTORY = []
    ITEM_LIST = [
        {"item": "Fox Cake",        "hp":1},
        {"item": "Cat Cookie",      "hp":0.8},
        {"item": "Potion",          "hp":0.7},
        {"item": "Cupcake",         "hp":0.5},
        {"item": "Bread",           "hp":0.4},
        {"item": "Apple",           "hp":0.25}
    ]

    def setPlayerName():
        os.system('cls')
        print('What is your name?')
        prompt = input('> ')
        if prompt != '': game.NAME = prompt
        print('')
        print('Your username:', game.NAME)
        print('')

    def setPlayerStat():
        print('Choose the class:')
        print('1 > Scout')
        print('2 > Assasin')
        print('3 > Tank')
        prompt = input('> ')
        if prompt == '':
            gamelevel = randint(1,3)
        else:
            gamelevel = int(prompt)

        if gamelevel > 3: gamelevel = 3
        if gamelevel < 1: gamelevel = 1

        if gamelevel == 1: game.CLASS, game.DMG, game.DEF, game.HP = 'Scout', randint(4,6), randint(4,6), randint(3,5)
        if gamelevel == 2: game.CLASS, game.DMG, game.DEF, game.HP = 'Assasin', randint(6,8), randint(5,7), randint(6,8)
        if gamelevel == 3: game.CLASS, game.DMG, game.DEF, game.HP = 'Tank', randint(5,7), randint(7,9), randint(4,6)
        print('')

        for i in range(3): game.grantItem(False)

        print('Your stats:')
        print('- Class:', game.CLASS)
        print('- ATK:', game.DMG)
        print('- DEF:', game.DEF)
        print('- HP:', game.HP)

    def setEnemy(level, mult, showInfo = True):
        if level == 1: game.ECLASS, game.EDMG, game.EDEF, game.EHP = 'Mini-Droid', randint(4,6), randint(4,6), randint(5,7)
        if level == 2: game.ECLASS, game.EDMG, game.EDEF, game.EHP = 'Droid', randint(5,7), randint(6,8), randint(8,10)
        if level == 3: game.ECLASS, game.EDMG, game.EDEF, game.EHP = 'Sky-Droid', randint(7,9), randint(5,7), randint(6,8)
        else: game.ECLASS, game.EDMG, game.EDEF, game.EHP = 'КБ', randint(30,60), randint(15,30), randint(100,200)

        game.EDMG *= mult
        if mult > 2: game.EDEF *= mult//3
        game.EHP *= mult

        if showInfo:
            print('Enemy stats:')
            print('- Class:', game.ECLASS)
            print('- ATK:', game.EDMG)
            print('- DEF:', game.EDEF)
            print('- HP:', game.EHP)
    
    def useItem():
        heal = 0
        if len(game.INVENTORY) > 0:
            item = sorted(game.INVENTORY)[0]
            game.INVENTORY.remove(item)

            for check in game.ITEM_LIST:
                if item == check["item"]: heal = check["hp"]
            
            print('You used', item,'. Restored', round(game.HP * heal), 'HP!')
        else:
            print('No items to use.')

        return heal
    
    def grantItem(showInfo = True):
        random = randint(0,len(game.ITEM_LIST)-1)
        item = game.ITEM_LIST[random]["item"]

        if showInfo: print('You got,', item +'!')
        game.INVENTORY.append(item)

    def grantLevel(showInfo = True):
        if game.EXP >= 100:
            game.LEVEL += (game.EXP // 100)
            game.EXP = 0

            print('New level! - ', game.LEVEL)
            if showInfo: print('')

            mult = 2
            if game.LEVEL > 5: mult = (game.LEVEL // 5) + 2

            if showInfo:
                print('Your stats:')
                print('- Class:', game.CLASS)
                print('- ATK:', game.DMG, '(+'+ str(mult//2) +')')
                print('- DEF:', game.DEF, '(+'+ str(mult//3) +')')
                print('- HP:', game.HP, '(+'+ str(mult) +')')

            game.DMG += mult//2
            game.DEF += mult//3
            game.HP += mult

    def battle():
        os.system('cls')
        
        turn = False
        curHP, expHP, youract, enemact = game.HP, game.EHP, 0, 0

        while game.EHP > 0 and curHP > 0:
            turn = not turn

            if not turn:
                if youract != 3:
                    print(game.ECLASS,'makes a move.')
                    sleep(0.5)
                    enemact = randint(1,2)
                    if enemact == 1: 
                        print(game.ECLASS,'decided to attack!')
                        sleep(0.5)
                        curHP = round(curHP - (game.EDMG / game.DEF))
                    else:
                        if randint(1,10) % 4 != 0:
                            print(game.ECLASS,'dodged unsuccessfully!')
                            sleep(0.5)
                        else:
                            print(game.ECLASS,'dodged successfully!')
                            sleep(0.5)
                            if youract == 1: game.EHP = round(game.EHP + (game.DMG / game.EDEF))
                else:
                    print(game.ECLASS,'skips their turn.')
                    sleep(0.5)

            if turn:
                print('Your HP:', curHP)
                print('Enemy HP:', game.EHP)
                print('')

                curitem = '?'
                if len(game.INVENTORY) > 0: curitem = sorted(game.INVENTORY)[0]

                print('What are you going to do,',game.NAME + '?')
                print('1 > Attack')
                print('2 > Dodge')
                print('3 > Use an item ['+curitem+']')
                print('Inventory:', sorted(game.INVENTORY))

                prompt = input('> ')
                if prompt == '':
                    youract = randint(1,3)
                else:
                    youract = int(prompt)
                    if youract > 3: youract = 3
                    if youract < 0: youract = 0
                print('')

                if youract == 1:
                    print('You attack!')
                    sleep(0.5)
                    game.EHP = round(game.EHP - (game.DMG / game.EDEF))
                elif youract == 2:
                    if randint(1,10) % 4 != 0:
                        print('You dodge unsuccessfully!')
                        sleep(0.5)
                    else:
                        print('You dodge successfully!')
                        sleep(0.5)
                        if enemact == 1: curHP = round(curHP + (game.EDMG / game.DEF))
                else:
                    curHP += round(game.HP * game.useItem())
                    if curHP >= game.HP: curHP = game.HP

            if not turn: os.system('cls')

            if curHP < 0: curHP = 0
            if game.EHP < 0: game.EHP = 0
        
        print('Your HP:', curHP)
        print('Enemy HP:', game.EHP)
        print('')

        if curHP > 0: 
            print('You won!')

            if randint(1,10) % 4 == 0: game.grantItem()

            game.EXP += (10 * expHP)
            game.grantLevel()

        else:
            print('You lost!')

        sleep(2)
        print('')
    
# RPG v0.2.4

game.setPlayerName()
game.setPlayerStat()

sleep(2)
os.system('cls')

print('You are walking along the forgotten edges of the old city.')
sleep(1)
print('There is a fork in the road.')
sleep(2)
print('')

game.setLocation()

sleep(2)
print('Someone is in your way...')
sleep(2)
print('You are being attacked by droids!')
sleep(2)
print('')

for i in range(25):
    os.system('cls')
    print(str(24-i) + ' enemies left!')
    print()

    game.encounterEnemy()

print('')

sleep(5)
print('You\'re tired.')
sleep(2)
print('One enemy left...')
sleep(2)
print('That\'s going to be the last battle.')
sleep(2)
print('')

os.system('cls')
game.encounterEnemy(True)

print('')
print('The end. Thanks for playing!')
