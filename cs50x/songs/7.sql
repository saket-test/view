SELECT AVG(energy) AS Avg_Drake_songs_Energy
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name = "Drake"
);
