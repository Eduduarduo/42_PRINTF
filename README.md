
# ft_printf
Printf Reimplementation - 42 São Paulo

### Flags

| Flag  | Description														 |
|-------|--------------------------------------------------------------------|
| **-** | Align replaced text to the left when enough width is given         |
| **0** | Add '0' as a padding character in numeric conversions              |
| **+** | Add a plus sign ('+') in the front of positive numeric conversions |
| **#** | Alternate input method for placeholder                             |

### Conversions

| Conversion | Description					|
|------------|------------------------------|
| **c**		 | int converted to ASCII char	|
| **s**		 | NULL - terminated string		|
| **p**		 | Pointer memory address		|
| **d**		 | int in decimal base			|
| **i**		 | int in decimal base			|
| **x**		 | int in hex base (lowercase)	|
| **X**		 | int in hex base (uppercase)	|
| **%**		 | '%' char literal				|
