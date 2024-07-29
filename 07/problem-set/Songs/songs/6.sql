SELECT songs.name AS song FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = 'Post Malone';
