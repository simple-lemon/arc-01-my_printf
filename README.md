## Overview
 my_printf is so dificult
## Features

- Interactive Printf game with a user-friendly interface.
- Customizable game settings, such as code length and the number of allowed guesses.
- Well-designed feedback to help the codebreaker refine their guesses.

## Getting Started

### Installation

1. Clone the repository:

   ```bash
    git clone https://github.com/muhammadnurullayev/arc-01-my_printf.git
   ```

2. Navigate to the project directory:

   ```bash
    cd my_printf
   ```

3. Build the project using the provided Makefile:

   ```bash
    make -f Makefile.mak
   ```

### Usage

- Start the game:

  ```bash
    ./printf [-c secret_code] [-t attempts]
  ```


- Optional command line arguments:

-c: Set the secret code manually. If not provided, a random code will be generated.
-t: Set the number of attempts. Default is 10.

- Gameplay
Follow the on-screen prompts to make guesses. The game provides feedback on each guess, and you can enter "stop" at any time to end the game.

## Contact

- muhammadnurullaev10@gmail.com