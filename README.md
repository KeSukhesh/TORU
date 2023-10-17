# TORU
**we ❤️ project management**

## Contents

[[_TOC_]] - ok this is broken but I will fix it later :D

## Change Log
N/A

## 🫡 0. Overview 
Hello! **TORU**, a project management web app is something I am developing in hopes of teaching myself OOP with Java, FE with React and TS, Dbs with postgreSQL and becoming a better software engineer having made this (to-be) serverless web app.

If you'd like to read about the steps I took throughout this software development process, I'll be updating this README.md file below, detailing my journey taken along this project.


## 😋 1. Stage 0: Getting Started

### 😋 1.1. Tasks
In this warm-up of a stage, I:
- Designed [our swagger.yaml file](swagger.yaml) to detail the routes we will be implementing for **TORU**,
- Wrote out any relevant interfaces for documentation purposes,
- Set up my project by:
    - stubbing our code (and practising our Python scripting by writing a test file to check if we did this right),
    - getting Spring Boot up and going, as well as our 
    - PostgreSQL database set up.

And of course, we followed the best practices for git and teamwork. 😉

### 😋 1.2. Data Types
| Variable Name | Type |
| --- | --- |
| is exactly **error** | `string`, with the value being a relevant error message of your choice |
| contains suffix **Id** | `number`, specifically integer |
| is exactly **message** | `string` |
| is exactly **sender** | `string` |
| is exactly **title** | `string` |
| is exactly **content** | `string` |
| is exactly **comment** | `string` |
| contains the prefix **time** | `number`, specifically an [**integer UNIX timestamp**](https://flaviocopes.com/how-to-get-timestamp-javascript/) in **seconds** (not milliseconds!). |
| is exactly **comments** | `Array` of objects, where each `object` contains the keys `{commentId, sender, comment, timeSent}` |
| is exactly **post** | `object` containing keys `{postId, sender, title, timeSent, content, comments}` |
| is exactly **posts** | `Array` of objects, where each `object` contains the keys `{postId, sender, title, timeSent}` |

### 😋 1.3. Testing
We have written a simple Python script *insert name* to test if we did this stage correctly or not. This script checks for whether our function stubs return the right things, and thus have been stubbed correctly according to our designed specification.

## 🔍 2. Stage 1: Basic Functionality and Tests

### 🔍 2.1. Tasks
This stage consisted of two main stages:
 - ***Writing tests*** for the basic functionality of **TORU**. These tests will be as small and independent as possible, so we can identify why a particular test may be failing more easily, and they must also be black box unit tests.
  - ***Implementing*** the basic functionality of **TORU**. The basic functionality is actually defined according to the interface section detailed in [our interface provided](swagger.yaml). 
