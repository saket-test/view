console.log("Welcome to Spotify");

// Initialize the Variables
let songIndex = 0;
let audioElement = new Audio('/static/songs/1.mp3');
let masterPlay = document.getElementById('masterPlay');
let myProgressBar = document.getElementById('myProgressBar');
let gif = document.getElementById('gif');
let masterSongName = document.getElementById('masterSongName');
let songItems = Array.from(document.getElementsByClassName('songItem'));
const PATH = "http://127.0.0.1:5000/";

let songs = [
    {songName: "Warriyo - Mortals [NCS Release]", filePath: "/static/songs/1.mp3", coverPath: "/static/covers/1.jpg", song_length: "03:50"},
    {songName: "Cielo - Huma-Huma", filePath: "/static/songs/2.mp3", coverPath: "/static/covers/2.jpg", song_length: "02:33"},
    {songName: "DEAF KEV - Invincible [NCS Release]-320k", filePath: "/static/songs/3.mp3", coverPath: "/static/covers/3.jpg", song_length: "04:33"},
    {songName: "Different Heaven & EH!DE - My Heart [NCS Release]", filePath: "/static/songs/4.mp3", coverPath: "/static/covers/4.jpg", song_length: "04:27"},
    {songName: "Janji-Heroes-Tonight-feat-Johnning-NCS-Release", filePath: "/static/songs/5.mp3", coverPath: "/static/covers/5.jpg", song_length: "03:28"},
    {songName: "Rabba - Salam-e-Ishq", filePath: "/static/songs/2.mp3", coverPath: "/static/covers/6.jpg", song_length: "03:28"},
    {songName: "Sakhiyaan - Salam-e-Ishq", filePath: "/static/songs/2.mp3", coverPath: "/static/covers/7.jpg", song_length: "04:33"},
    {songName: "Bhula Dena - Salam-e-Ishq", filePath: "/static/songs/2.mp3", coverPath: "/static/covers/8.jpg", song_length: "03:50"},
    {songName: "Tumhari Kasam - Salam-e-Ishq", filePath: "/static/songs/2.mp3", coverPath: "/static/covers/9.jpg", song_length: "03:28"},
    {songName: "Na Jaana - Salam-e-Ishq", filePath: "/static/songs/4.mp3", coverPath: "/static/covers/10.jpg", song_length: "04:27"},
]

songItems.forEach((element, i)=>{ 
    element.getElementsByTagName("img")[0].src = songs[i].coverPath; 
    element.getElementsByClassName("songName")[0].innerText = songs[i].songName; 
    element.getElementsByClassName("timestamp")[0].innerText = songs[i].song_length;
})

// Handle play/pause click
masterPlay.addEventListener('click', ()=>{
    if(audioElement.paused || audioElement.currentTime<=0){
        audioElement.play();
        masterPlay.classList.remove('fa-play-circle');
        masterPlay.classList.add('fa-pause-circle');
        gif.style.opacity = 1;
    }
    else{
        audioElement.pause();
        masterPlay.classList.remove('fa-pause-circle');
        masterPlay.classList.add('fa-play-circle');
        gif.style.opacity = 0;
    }
})




// Listen to Events
audioElement.addEventListener('timeupdate', ()=>{ 
    // Update Seekbar
    progress = parseInt((audioElement.currentTime/audioElement.duration)* 100);
    console.log(audioElement.duration)
    myProgressBar.value = progress;
    myProgressBar.addEventListener('change', ()=>{
        audioElement.currentTime = myProgressBar.value * audioElement.duration/100;
    })
    document.getElementsByClassName('timelapsed')[0].innerHTML = `${formatTime(audioElement.currentTime)} - ${formatTime(audioElement.duration)}`
})


// myProgressBar.addEventListener('change', ()=>{
//     audioElement.currentTime = myProgressBar.value * audioElement.duration/100;
// })

const makeAllPlays = () => {
    Array.from(document.getElementsByClassName('songItemPlay')).forEach((element) => {
        element.classList.remove('fa-pause-circle');
        element.classList.add('fa-play-circle');
    });
}

// Convert seconds into minute:second format
function formatTime(seconds) {
    let minutes = Math.floor(seconds / 60);
    let remainingSeconds = Math.floor(seconds % 60);

    // Add leading zeros if needed
    minutes = String(minutes).padStart(2, '0');
    remainingSeconds = String(remainingSeconds).padStart(2, '0');

    return `${minutes}:${remainingSeconds}`;
}

Array.from(document.getElementsByClassName('songItemPlay')).forEach((element) => {
    element.addEventListener('click', (e) => {
        if (audioElement.paused || audioElement.src !== `${PATH}static/songs/${parseInt(e.target.id) + 1}.mp3`) {
            // Only change if the clicked song is different or the audio is paused

            makeAllPlays();
            songIndex = parseInt(e.target.id);
            e.target.classList.remove('fa-play-circle');
            e.target.classList.add('fa-pause-circle');
            audioElement.src = `/static/songs/${songIndex + 1}.mp3`;
            masterSongName.innerText = songs[songIndex].songName;
            audioElement.currentTime = 0;
            audioElement.play();
            gif.style.opacity = 1;
            masterPlay.classList.remove('fa-play-circle');
            masterPlay.classList.add('fa-pause-circle');
        } 
        else {
            // If the clicked song is the same and the audio is playing, stop it
            audioElement.pause();
            audioElement.currentTime = 0;
            // makeAllPlays();
            masterPlay.classList.remove('fa-pause-circle');
            masterPlay.classList.add('fa-play-circle');
            e.target.classList.remove('fa-pause-circle');
            e.target.classList.add('fa-play-circle');
            audioElement.pause();
            gif.style.opacity = 0;
        }
    });
});


document.getElementById('next').addEventListener('click', ()=>{
    if(songIndex>=9){
        songIndex = 0
    }
    else{
        songIndex += 1;
    }
    audioElement.src = `/static/songs/${songIndex+1}.mp3`;
    masterSongName.innerText = songs[songIndex].songName;
    audioElement.currentTime = 0;
    audioElement.play();
    masterPlay.classList.remove('fa-play-circle');
    masterPlay.classList.add('fa-pause-circle');

})

document.getElementById('previous').addEventListener('click', ()=>{
    if(songIndex<=0){
        songIndex = 0
    }
    else{
        songIndex -= 1;
    }
    audioElement.src = `/static/songs/${songIndex+1}.mp3`;
    masterSongName.innerText = songs[songIndex].songName;
    audioElement.currentTime = 0;
    audioElement.play();
    masterPlay.classList.remove('fa-play-circle');
    masterPlay.classList.add('fa-pause-circle');
})

