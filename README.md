# (੭｡╹▿╹｡)੭ so_long
![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-black)

This project is a small 2D game with minilibx. You'll learn about textures, sprites and tiles.

![image](https://user-images.githubusercontent.com/51353146/152220218-a4bda6e5-9f31-4fff-9816-95958ebfff07.png)

## Preview
![ezgif com-gif-maker](https://user-images.githubusercontent.com/51353146/152325175-0d3510c5-3b9e-47c1-a696-f9528e86f96e.gif)


## How play the game
To play this game you can use any map of your choice as long follow the following rues:

* The extension need be `.ber`
* Its must be rectangular, surrounded by wall `1`
* Must have only one exit, only one player and at least one collectible
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
|     *F*     | Enemy starting position  |

In folder [map_file](map_file) have some examples of maps.

### Control of play
You can use `AWSD` to move `UP`, `DOWN`, `LEFT`, `RIGHT`.  
For restart the game press `ESC` or click on the red cross of window.
If you touch the enemy you loose the game.
To win the game its necessary pick up all collectible and pass for the exit.

### How execute the game
To start the game you need run the command `make` root directory.
This will compile the executable file `so_long`, to execute its necessary run `./so_long map_file/map.ber` `./so_long_bonus map_file/map.ber` or any map of your choice.

## Makefile rules

| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make bonus` | Compile the bonus program                               |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program                |
