--print the number of movies rated 10
SELECT COUNT(title) FROM movies JOIN ratings on movies.id = ratings.movie_id WHERE rating = 10;