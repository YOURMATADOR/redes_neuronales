# Perceptron

The simplest [Perceptron](https://en.wikipedia.org/wiki/Perceptron) you'll ever see.

## How to use

Let's suppose you have the following data set:

| Height (cm) | Weight (kg) | Class (0-1) |
|-------------|-------------|-------------|
| 180         | 80          | 0           |
| 175         | 67          | 0           |
| 100         | 30          | 1           |
| 120         | 32          | 1           |

0 - adult  
1 - child

You need to process the table to this format:

```
const x = [
	[180, 80],
	[175, 67],
	[100, 30],
	[120, 32]
];

const y = [0,0,1,1];
```

Then just create a new Perceptron passing the shape of the data (height and weight), the learning rate and the number of iterations. By default the learning rate is set to 0.01 and the number of iterations is set to 10.

```
const p = new Perceptron( x[0].length );
```

Call the fit function

```
p.fit(x,y);
```

And you're all set to make predictions

```
p.predict([178, 70])
```

Super simple.

# Applications

[Can a simple perceptron drive a car in a game?](https://github.com/victorqribeiro/carGamePerceptron)
