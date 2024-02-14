# Spotify Clone
### Video Demo:  https://youtu.be/E_j9VaQp1fk
## Description:
#### - I have made my Spotify Clone in FLask framework.
#### - The website has 3 pages: Home, About, and Songs.
#### - app.py contains simple routes to all the pages of the website. There are 2 folders: "static" and "templates" (ignoring __pycache__ and venv)
#### - static contains all the material (songs mp3 files, cover images) and CSS, JS, img file for basic images used.
#### - There are 3 CSS files, 1 for each page. Including font imports. There are 2 JS files. 1 for songs and 1 for about page. I used links in home page to go to other 2 pages so JS was not needed.
#### - JS of about page waits for page to load and then adds the content. JS for songs page handles play/pause, showing songs content to user, updating current time and total time of song, changing symbols based on if song is playing or not. Also handles next and previous button to change songs.
#### - Templates has the HTML for the 3 pages.
#### - About page has information about the Team. Home page is the front welcome page. Songs page has the songs.

#
## About the Website

### This Website has 3 pages: Home, Songs, and About.
#### Every page has a navbar fixed on top with 3 buttons that lead to the 3 pages.

### Home: 
#### - Single Button that leads to songs page.

### About: 
#### - Custom color on selecting text.
#### - Simple alert popup on clicking contact Buttons.
#### - Hover color change on buttons.
#### - boxes adjust based on viewport width.
#### - Text div has a gradient background.

### Songs:
#### - Custom color on selecting text.
#### - Hover color change on play/pase buttons
#### - Time stamp of song and total time in min:sec format.
#### - Background color changes based on width of page.
#### - Play pause buttons next to songs work nicely.
