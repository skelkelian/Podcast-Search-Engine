[![Contributors][contributors-shield]][contributors-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
[![Python][python-shield]][python-url]

# Podcast-Search-Engine

## Table of Contents
[About](#about)  
[Product Goal](#product-goal)  
[Product Features](#product-features)  
[Users](#users)  
[Edge Cases](#edge-cases)  
[Model Evaluation](#model-evaluation)  
[System Diagram](#system-diagram)  
[Installation](#installation)  
[Contributing](#contributing)  
[License](#license)  

## About
This project uses Machine Learning to determine the topic/person being discussed in a podcast and allows users to search by topic/person and view clips/segments regarding that topic.

#### Sample Input
<p align="center">
    <img src=search_engine.png> 

#### Sample Output
[Joe Rogan Experience #1439 - Michael Osterholm (0:28)](https://youtu.be/E3URhJx0NSw?t=28)  
[Viral: The Origin of Covid 19 | Matt Ridley | EP 310 (5:20)](https://youtu.be/FEh5JyZC218?t=320)  
[Vincent Racaniello: Viruses and Vaccines | Lex Fridman Podcast #216 (1:22:25)](https://youtu.be/G433fa01oMU?t=4945)
    
### Product Goal
Include support for every podcast upwards of 10,000 monthly listeners.

### Product Features
Allows users to search for segments of podcast based on topics.

More will be added soon!

### Users
The Podcast Search Engine could be used by podcast listeners and podcasters. Podcast listeners could use this to browse clips about a specific topic/person and podcasters could use this for analytics and determine topics that are oversaturated/undersaturated.

### Edge Cases
1. There are several topics that could be predicted after the model listens to a clip.
2. Different people speaking in a clip could be a hint of the topic being spoken about.
3. Ads during the podcast should be ignored by the model.

### Model Evaluation
The accuracy of the model will be determined manually by using podcast episodes that I am familiar with and search for topics I know are discussed. As this project expands, I will develop a new way of testing the accuracy of the model that is more time effective than manual testing.

### System Diagram
<p align="center">
    <img src=system_diagram.png> 

## Installation

#### Create a virtual environment
```
virtualenv -p python3
```
#### Activate your virtual environment
```
source bin/activate
```
#### Install Jupyter
```
pip install jupyter notebook
```
#### Start Jupyter
```
jupyter notebook
```

## Contributing
### File Bugs using Pull Requests
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. 

## License
[MIT](https://choosealicense.com/licenses/mit/)

<p align="left">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/skelkelian/Podcast-Search-Engine/graphs/contributors
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/skelkelian/Podcast-Search-Engine/issues
[commits-shield]: https://img.shields.io/github/commit-activity/y/skelkelian/Podcast-Search-Engine
[commits-url]: https://github.com/skelkelian/Podcast-Search-Engine/graphs/commit-activity
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://choosealicense.com/licenses/mit/
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/skelkelian/
[python-shield]: https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54
[python-url]: https://www.python.org

