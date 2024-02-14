document.addEventListener('DOMContentLoaded', function() {
    // Dynamically load content using JavaScript
    loadAboutContent();
});

function loadAboutContent() {
    // Simulate asynchronous content loading
    setTimeout(function() {
        const aboutContent = `
            <p>Welcome to the Spotify Clone website! This project was created to showcase a simplified clone of the popular music streaming service, Spotify.</p>
            <p>Why did I make this website?</p>
            <p>As a music enthusiast and a web developer, I wanted to explore and demonstrate my skills by creating a clone of a well-known platform. Spotify provides a great user experience, and attempting to replicate some of its features was both challenging and rewarding.</p>
            <p>What is Spotify?</p>
            <p>Spotify is a music streaming service that offers a vast library of songs, playlists, and podcasts. Users can discover, play, and share their favorite music. It provides a seamless and enjoyable way to access a world of music.</p>
            <p>Feel free to explore the website and enjoy the music!</p>
        `;

        document.getElementById('content').innerHTML = aboutContent;
    }, 500); // Simulated delay for content loading
}

const buttons = document.querySelectorAll('.button');

// Add event listener to each button
buttons.forEach(button => {
    button.addEventListener('click', () => {
        alert("Your contact info has been shared. We will reach out to you soon.");
    });
});