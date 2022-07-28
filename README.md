
<h1 align="center">
  push_swap
  <br>
</h1>

<h4 align="center">Because Swap_push isn’t as natural.
<br>
<br>
</h4>

<p align="center">
  <a href="https://github.com/ThomasRobertson/42-push_swap">
    <img src="https://img.shields.io/tokei/lines/github/ThomasRobertson/42-push_swap?style=flat-square"
         alt="Line of Code">
  </a>
  <a href="https://github.com/ThomasRobertson/42-push_swap">
    <img src="https://img.shields.io/github/languages/code-size/ThomasRobertson/42-push_swap?style=flat-square"
         alt="Size">
  </a>
  <a href="https://github.com/ThomasRobertson/42-push_swap">
    <img src="https://img.shields.io/github/license/ThomasRobertson/42-push_swap?style=flat-square"
         alt="License">
  </a>
  <a href="https://github.com/ThomasRobertson/42-push_swap">
    <img src="https://img.shields.io/github/languages/top/ThomasRobertson/42-push_swap?style=flat-square"
         alt="License">
  </a>
  <a href="https://github.com/ThomasRobertson/42-push_swap/actions/workflows/norminette-action.yml">
    <img src="https://github.com/ThomasRobertson/42-push_swap/actions/workflows/norminette-action.yml/badge.svg"
         alt="Norminette Action">
  </a> 
</p>

<p align="center">
  <a href="#summary">Summary</a> •
  <a href="#how-it-work">How It Work</a> •
  <a href="#target">Target</a> •
  <a href="#benchmarks">Benchmarks</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#how-to-use---bonus-part">How To Use - Bonus Part</a> •
  <a href="#license">License</a>
</p>

## Summary

This project sort data using two stacks, using
the lowest possible number of actions.

> This project is part of 42 Paris' curriculum. You can check the full subject in the subject pdf included in this repo.

## How It Work

To achieve that, the algorithm will first move every number to the second stack, called stack_b, except for three number still in the first stack, called stack_a.

After sorting the remaining three numbers, it will calculate the cost for each number in stack_b to be added, and sorted, into the stack_a. It will always choose the number with the lowest cost. It will repeat this process until every number is sorted.

## Target

This program aim at 100% completion and has to sort different size of stack with a maximum number of actions :

* 3 values : no more than 3 actions
* 5 values : no more than 12 actions
* 100 values : no more than 700 actions
* 500 values : no more than 5 500 actions

## Benchmarks

The program was benchmarked using the mean of 100 runs. The range is shown in parentheses.

* 3 values : mean of 1 (0-2)
* 5 values : mean of 8 (6-10)
* 100 values : mean of 561 (540-586)
* 500 values : mean of 4543 (4384-4819)

Bonus :

* 1000 values : mean of 11559
* 2000 values : mean of 29536


## How To Use

Clone this GitHub repos

```bash
git clone https://github.com/amitmerchant1990/electron-markdownify
```
Use the provided Makefile to compile to program (using the system's cc)

```bash
make
```
Run the program and provided it with a list of integers

```bash
./push_swap 7302 3 18 -928 12 0
```
Or this syntax
```bash
./push_swap "7302 3 18 -928 12 0"
```
*Note for 42 Students : the second way is not required by the subject. It is a misconception caused by using zsh instead of bash. See Slack or Discord for more infos.*

## How To Use - Bonus Part

The Makefile include a checker program that can be compiled with
```bash
make bonus
```
And then run with either
```bash
./checker 7302 3 18 -928 12 0
```
Or
```bash
./checker "7302 3 18 -928 12 0"
```
The program will then wait for inputs. Each action has to be followed by a new line.
Once every action has been submitted, use Ctrl+D.

## License

MIT
