
class NameNumber:
    def __int__(self):
        self._name = ""
        self._number = 0
        
    def set_name(self, name):
        self._name = name
        
    def set_number(self, number):
        self._number = number
        
    def get_name(self):
        return self._name
        
    def get_number(self):
        return self._number
        
if __name__ == '__main__':
    test = NumberNumber()
    test.set_name("xx")
    test.set_number(23)
    print(test.get_name())
    print(test.get_number())
        