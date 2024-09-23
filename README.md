# 🍺 PivoH: The Ultimate Beer Visualization Framework

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C Standard](https://img.shields.io/badge/C-C99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Refreshment Level](https://img.shields.io/badge/Refreshment-100%25-brightgreen.svg)](https://en.wikipedia.org/wiki/Beer)

## 🚀 Why PivoH?

Are you tired of boring, static console outputs? Do you yearn for a more refreshing development experience? Look no further! PivoH is here to quench your thirst for innovative C programming!

PivoH transforms your terminal into a lively pub, complete with a beautifully rendered, animated beer glass. It's not just a visualization - it's a revolution in console-based hydration technology!

## 🌟 Features

- **Realistic Beer Physics**: Watch in awe as your virtual beer is poured with stunning accuracy!
- **Dynamic Bubble Animation**: Experience the effervescence of your digital brew!
- **Foam Simulation**: Marvel at the frothy head, complete with slight overflow for that authentic pub feel!
- **ANSI Color Support**: Enjoy your beer in vivid, thirst-quenching colors!
- **Customizable Beer Attributes**: Tailor your virtual brew to your exact specifications!

## 🛠 Installation

```bash
git clone https://github.com/yourusername/PivoH.git
cd PivoH
mkdir build
cd build
cmake ..
make
```

## 🍻 Usage

```c
#include "pivo.h"

#define BUBBLE_COLOR "\033[36m"
#define RESET_COLOR "\033[0m"

int main() {
  srand(time(NULL));

  BeerGlass mug;
  char bubbles[] = {'o', 'O', '*', 'B', 'b', 'o', 'O', 'B', 'b'};
  init_beer_glass(&mug, 15, 30, '~', '#', bubbles,
                  sizeof(bubbles) / sizeof(bubbles[0]));

  printf("\033[2J");
  printf("\033[H");

  display_beer(&mug);

  return 0;
}

```

## 🎓 Why C is the Ultimate Programming Language

1. **Unparalleled Performance**: C gives you the power to optimize every byte!
2. **Low-Level Control**: Manipulate memory like a true coding artisan!
3. **Portability**: Write once, compile anywhere!
4. **Foundational Knowledge**: Master C, and you'll understand all programming!
5. **Beer Visualization**: With PivoH, C is now the only language that truly understands beer!

## 🤝 Contributing

We welcome all beer enthusiasts and C aficionados to contribute to PivoH! Whether it's adding new beer styles, optimizing bubble algorithms, or enhancing foam physics, your contributions can help make PivoH the world's premier beer visualization framework!

## 📜 License

PivoH is MIT licensed, because sharing is caring, just like a round of beers with friends!

## 🎉 Conclusion

Don't let your console stay dry any longer! Dive into PivoH and experience the future of refreshment-oriented programming. Remember: Friends don't let friends use languages that can't visualize beer!

Cheers to C, and happy coding! 🍻
