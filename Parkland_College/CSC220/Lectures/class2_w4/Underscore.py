#!/usr/local/bin/python3

THis_is_a_very_long_variable = 10
print(THis_is_a_very_long_variable)

class Wizard:
    _wizards = []
    wizards = []
    def_ = 10

    def access_priivate_wizard():
            return Wizard._wizards

# discouraged!!!
print(Wizard._wizards)

# do this instead:
print(Wizard.access_priivate_wizard())

print(Wizard.wizards)


# double underscore == "dunder"
# case 1: leading dunder: __var
# case 2: enclsoing dunder: __init__

class Dunder:
    _dunder = []

    #case 2: enclosing
    def __init__(self, mana):
        self.mana = mana
        #enforces: keep me private!
        self.__supersecretphrase = "wingardium levioso"

    def __str__(self):
        return "This dunder has " + str(self.mana) + " mana left"

    def __add__(self, other):
        return Dunder(self.mana + other.mana)



tom = Dunder(1000)
harry = Dunder(101)

traay = tom + harry
print(tom)
print(traay)
#print(tom.__supersecretphrase)
#print(dir())
