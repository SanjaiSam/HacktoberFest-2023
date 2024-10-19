def intro():
    print(r"""
          ___  _          _       _       _        _       
         |_ _|| |        | |     | |     | |      | |      
          | | | |__   ___| |_    | |  ___| |_ __ _| |_ ___ 
          | | | '_ \ / _ \ __|   | | / _ \ __/ _` | __/ _ \
         | | | | | |  __/ |_    | ||  __/ || (_| | ||  __/
        |___||_| |_|\___|\__|   |_| \___|\__\__,_|\__\___|
    """)
    print("Welcome to Treasure Island!")
    print("Your mission is to find the treasure hidden on the island.\n")

def first_choice():
    print("You arrive at a fork in the road. Do you want to go 'left' or 'right'?")
    choice = input(">").lower()
    return choice

def second_choice():
    print("You encounter a mystical creature. Do you want to 'talk' to it or 'run' away?")
    choice = input(">").lower()
    return choice

def final_choice():
    print("You come across a cave with two entrances: 'dark' and 'light'. Which do you choose?")
    choice = input(">").lower()
    return choice

def play_game():
    intro()
    choice1 = first_choice()

    if choice1 == 'left':
        choice2 = second_choice()

        if choice2 == 'talk':
            choice3 = final_choice()

            if choice3 == 'light':
                print(r"""
                      __/\\__
                     |      |
                     |  💰  |
                     |______|
                """)
                print("Congratulations! You found the treasure! You win!")
            elif choice3 == 'dark':
                print(r"""
                     .--.
                    |o_o |
                    |:_/ |
                   //   \ \
                  (|     | )
                 /'\_   _/`\
                 \___)=(___/
                """)
                print("You were swallowed by a giant monster. Game over!")
        else:
            print("You tripped and fell into a pit. Game over!")

    else:
        print("You walked into a quicksand trap. Game over!")

if __name__ == "__main__":
    play_game()
