class Unit:

    def __init__(self, color):
        self.color = color

    def set_color(self, new_color):
        self.color = new_color
        return new_color
    
    def get_color(self):
        return self.color