import unit

class Grid:

    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.grid = self.build_grid()
        print(self.grid)

    def build_grid(self):
        grid = []
        for x in range(self.width):
            row = []
            for y in range(self.height):
                row.append(unit.Unit("brown"))
            grid.append(row)
        return grid  

    def get_width(self):
        return self.width
    
    def set_width(self, new_width):
        self.width = new_width

    def get_height(self):
        return self.height
    
    def set_height(self, new_height):
        self.height = new_height

def main():
    grid = Grid(150, 150)
    print(grid.get_height())

if __name__ == "__main__":
    main()