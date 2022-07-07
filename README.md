# Pencil

## 0. Introduction

Computer graphics often deals with digital images, which are made up of pixels. Pixels are stored as two-dimensional arrays of color data in a computer. The most straightforward way of creating or editing them is to change the values stored in these arrays.

In this lab, you will:

- Learn about how colors and images are represented digitally
- Experiment with making pixel art by modifying an image in code
- And in the end, implement a Photoshop-like "pencil" to draw interactively!

## 1. Before You Begin

Before you begin, here's some basic knowledge you'll need to work with labs (and projects) in CS123:

### 1.1. Stencil Code

Just like in `Lab 1: Setup`, we've provided you with some stencil code to get you started. As always, you should `git clone` this repository to your local machine and open the project in QtCreator.

### 1.2. Application Windows

Run the project by hitting the big "play" button, and you should see an application window (with nothing in it) appear. This will come in handy later!

[ Image of application window ]

> Interested in how GUI elements like these are set up? Feel free to take a look at [ TODO: these specific files ] in our stencil code!

### 1.3. Command Line Arguments

Most labs and projects in CS123 will use command line arguments to toggle between different configurations, and this lab is no different; specifically, you will be using it to select the type of canvas you wish to use.

[Screenshot of interface to set command line argument]

To set command line arguments, click into the `Projects` tab on the left sidebar. Under `Build and Run > Run > Command Line Arguments`, you can enter command line arguments which will be supplied to the application when it is run.

| Task 1                               |
| :----------------------------------- |
| Change the command line argument ... |

In this lab, we use command [] and [] to control if we want to show a black-and-white canvas or colorful canvas in the application window.

Once you're done with that, we may begin the lab proper!

## 2. Representing Colors

In computer graphics, **images** are often represented as 2D arrays of **pixels**, which are simply stores for some form of data.

> Technically, pixels can encode any kind of information. Later in CS123, we'll use [height maps](https://en.wikipedia.org/wiki/Heightmap) and [depth buffers](https://en.wikipedia.org/wiki/Z-buffering) to encode linear displacement, and even [normal maps](https://en.wikipedia.org/wiki/Normal_mapping) to encode directions!

Of course, as in digital pictures, pixels are most often used to encode **color** data.

In this section, we'll explore how we can represent color data in code.

### 2.1. Grayscale

A pixel in a grayscale image requires only a single number to encode its intensity:

![imagematrix](imagematrix.png)

Conventionally, we define 0 as the darkest color (completely black), and 1 as the lightest color (completely white). Like what we show in the picture above.

Correspondingly, 0.5 would be a medium-gray, and 0.7 would be a relatively lighter shade of gray.

### 2.2. RGBA

But grayscale images are kinda boring :(

Throughout this course, we define colors using the Red-green-blue-alpha (RGBA) model. Here, pixels have 4 color channels: red, green, blue and alpha.

The alpha channel represents the transparency of the color. You will work more with this concept in your project. For now, let's focus on red, green and blue.

For Instance, RGBA value of (255,0,0) represents a red color, and (255,0,255) adds blue to it to make purple.

<img src="RGB Slider Demo.jpg" alt="RGB Slider Demo" style="zoom:45%;" /><img src="RGB Slider Demo2.jpg" alt="RGB Slider Demo2" style="zoom:45%;" /><img src="Color Slider.jpg" alt="Color Slider" style="zoom: 45%;" />

Toggle the RGB color slider here: https://www.cssscript.com/demo/rgb-color-picker-slider/

How does the change in RGBA values affect the produced color?

### 2.3. A Note On Datatypes

Earlier, we used floats ranging from 0 to 1 to represent color intensities.

However, a typical `float` occupies 4 bytes, which is actually a pretty big memory size. Can we manage to make the image look roughly the same with less memory?

The answer is yes! If we only represent colors using integers ranging from 0 to 255, we can occupy only 1 byte per number. 

In C++, this data type is declared as  `uint8_t`, and we will be using it through out this course.

**Use int ranged 0-255 to represent colors**

In a 0-255 integer representation, we use 255 to denote the MAX color intensity, and use integers between 0 and 255 to represent the colors in between.

This is a very common color representation method, and you will be seeing it again and again in this course.

**Conversion Between the Two**

To convert between the above representations, we need to scale the number up or down. For instance, to convert from 0-255 integer representation to 0-1 float representation, simply divide all values by 255.

| Task 2                                                       |
| :----------------------------------------------------------- |
| In [function location], implement a method to convert 0-1 float representation to 0-255 integer representation.<br/><br/>**HINT**: you might want to check out round() function in cmath library. |

## 3. Your First Canvas

In order to operate on images, you need an image!

Let’s make a 2D canvas!

### 3.1. Creating "2D" Arrays

In lab 01, you learned that you can use containers like `std::vector` or `std::array` to store linear collections of data.

Collapsible section: Remind me: what are the differences between these ways of storing data? [Todo](Include information about memory management, make_unique, allocate and delete etc.)

However, these are 1-dimensional, and what we need is 2D!

There are two common ways of using 1D data-structures to represent 2D ones:

- row-major order, and
- column-major order

![](row-major-order-1.jpg)<img src="Colum-Major-Order.jpg" alt="Colum-Major-Order" style="zoom: 50%;" />

In this course, we store pixel data in row-major order, where arrays are arranged sequentially row by row, which means fillingi all the indices of the first row and then moving on to the next row.

Above is an example of filling indices of a 2 x 4 array. When accessing pixels in an image by their xy coordinates, you should compute its index in the array. 

**task**:

Now, lets create our very own image. We'll start with the basic: creating a grayscale image:

- In function ….initialize a "gray canvas" of 10 x 10 pixels by creating a std::vector in [location].

- Set the initial value of all its elements to 123. (Instead of using for loops, you might want to consider faster way of doing it. For example, look up std::fill may help you)

**task**:

- Display what you just created by passing the vector to `displayGrayCanvas()` at [location]
- Compile and run the code with command line input of [...], make sure it's correct!

Do you see a gray box?

From now on, we will be using this image as our 'canvas'. We'll teach you how to 'draw' on it.

### 3.2. Modifying "2D" Arrays

By modifying data values in the array you just created, you can make the corresponding points, or pixels turn to different colors.

You can try changing a random data to 255 and observe what happen.

A white dot showed up on your canvas, right?

Your job in this section, is to work our which pixel correspond to which element in the array, and change their values. Refer to the explanation on row-major-order for hint.

**task:**

- Match “this image” by indexing and changing values of the vector you just created.

![](canvas.jpg)

**task:**

- Take a screenshot of what you did.

### 3.3. **The RGBA Struct**

Now, it's time to spice things up!

Let's change the canvas to a colorful one. Instead of a std::vector of numbers, we will want a std::vector of something that contains all 4 values of r,g,b,a.

#### 2.2.1. Our CS1230 RGBA Struct

To group several related variables into one place, we should create a Struct.

Recall what you learned in Lab01 about structures and how to create them.

A naïve RGBA structure should have 4 members: red, green, blue, and alpha. We give you a simple example of how to define it below:

```c++
#ifndef NAIVE_RGBA
#define NAIVE_RGBA

struct NaiveRGBA
{
	int r;
	int g;
	int b;
	int a;
}
#endif
```

**task:**

Try defining a RGBA structure in your own code by copying the above code into a new header file.

To create a new file in Qt, right click on the left-side 'Project' bar, and select "Add New"

You should see an interface asking you to choose which kind of new file you want to add. In our task, you should select C/C++ header file.

[Screenshot]

Next, follow the interface instructions, define the name and location of your header file, and in project management section, select 'Done'. You should see a new header file appear in your chosen location after a few seconds.

[screenshot] [screenshot]

(My Qt tabs are in Chinese, need to find a English version to make screen shots)

<details>
  <summary>What does these all mean?</summary>


_Your structure is defined between_

```
#ifndef NAIVE_RGBA
#define NAIVE_RGBA
```

_and_

```
#endif
```

_'NaiveRGBA' is its name_

_Variables between brackets(int r; int g; int b; int a;) are its member variables_

_To make your life easier, you can also create member functions that works on the data members of the structure._

_(Examples of member function)_

</details>

To use the structure you just defined, you can simply include the header file at the top lines of your code and use it.

You don't have to do it here, as we have implemented a more complex RGBA structure for you in [location], and linked it for you.

<details>
  <summary>Array of struct</summary>

_An array is a collection of data items of the same type. So, just like ints, floats, chars etc., structs can be put into an array too._

In this course, we put RGBA structures into an array to make up our canvas, like shown below:

*canvas:*

| RGBA | RGBA | RGBA | ...  | RGBA |
| ---- | ---- | ---- | ---- | ---- |

_You can define a std::vector of RGBA structs like this:_

```c++
std::vector<RBGA> rgbaArray
```

_or you can allocate an array of RGBA like this (suppose you have a canvas of 10x10):_

```
RGBA rgbaCArray[100]
```

When an element in the array, for instance, rgbaArray[10] gets accessed, it returns the RGBA value at row 1, column 0

</details>

<details>
  <summary>Extra Info: struct of arrays</summary>

_Alternatively, you can also create a structure of arrays(this example assumes there are 10 x 10 pixels on a canvas):_

canvas:

| red  | red  | red  | ...  | red  |
| ---- | ---- | ---- | ---- | ---- |

| green | green | green | ...  | green |
| ----- | ----- | ----- | ---- | ----- |

| blue | blue | blue | ...  | blue |
| ---- | ---- | ---- | ---- | ---- |

| alpha | alpha | alpha | ...  | alpha |
| ----- | ----- | ----- | ---- | ----- |

*In code, the canvas as allocated like this:*

```C++
struct canvas {
	int r[100];
	int g[100];
	int b[100];
	int a[100];
};
```

_So r[0] represent the red intensity of pixel (0,0), g[0] represents the green intensity of pixel(0,0), and so on..._

\*The canvas we use in this class is an array of RGBA, but you are welcome to learn about the other one here: [Array of Structures vs. Array within a Structure in C/C++ - GeeksforGeeks](https://www.geeksforgeeks.org/array-of-structures-vs-array-within-a-structure-in-c-and-cpp/#:~:text=Below is the tabular difference between the Array,a%2C b%2C c%3B } students [ ... )

</details>

#### 2.2.2. Your Mission

Now, let's switch to a canvas that allows us to use colors!

**Task:**

- Modify your previous code to create a canvas with colors instead of grayscale only.

Consider the type of variable you want your std::vector to have.

- Set the initial values of RGBA to (0,123,123,1)

**Task:**

- Display the canvas by passing the vector to `displayGrayCanvas()` at [location]
- Compile and run the code with command line input of [...]

What is color of your canvas now?

**task**:

Now, in `drawFlower(vec2 xy)` at [code location], try changing the pixel at coordinate (x,y) to something other than the initial value. You should work out what its index should be.

**Task:**

Try making the function draw a flower with colorful center and petals, sort of like the example below(You can decide the color yourself):

![](bunch-colorful.jpg)

task :

- You can call `drawFlower(vec2 xy)` multiple times and change x,y coordinates to create more pixel flowers.

- take a screenshot of your creation

## 4. The Pencil Tool

Hope you had a little fun drawing flowers! Now, Instead of modifying a 2D canvas in code, we want to be able to modify it _interactively_.

### 3.1. CanvasWidget

The key to interactivity in Qt is events.

When events associated with particular _signals_ occur*,* Qt calls functions called _slots_. You don’t need to know how to use these, of course—we’ll (do our best to) handle everything Qt-related for you.

In this class, we will set up the functions that gets called when events occur for you, and you need to fill these functions.

### 3.2. Pencil

The functions `MouseDown()`, `MouseMove()`, and `MouseUp()` are called to change the canvas when the user interacts with the canvas with their cursor/mouse, we will Implement the event handlers in X file

#### 3.2.1. A Note On How To Survive A Weird Compromise: C Arrays

Though we recommend using std::vector (and std::array) for all your canvas needs, Qt’s canvas … so we’ll use C arrays here. However! It’s used the same way.

</details>

<details>
  <summary>Want to know why Qt does this?</summary>


We don’t know.

</details>

_Images displayed in QT have to be a type called 'QImage', and they are defined to be C arrays. Unfortunately, this implementation is hard to circumvent, so you have to work with C arrays when dealing with QT._

[By calling canvas->data], your program returns a pointer to the array of canvas pixels, which are RGBA structs. Your [] function returns a xy coordinate of your mouse in canvas space. Again, you need to work on solving the index for your pixel, and find a way to modify it.

#### 3.2.2 Leaky Pencil

Implement `pencilMove` such that it colors the pixel it’s currently on.

#### 2.2.3 Good Pencil

Implement `pencilDown` and `pencilUp` such that the pencil only colors pixels when the mouse is held down.

A Boolean variable in pencil class may be useful.

HINT: What happens when you click without moving?

## 5. Conclusion

Prepare the two screenshots and your good pencil to get checked off!
