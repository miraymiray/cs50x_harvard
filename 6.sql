-- print the average rating of 2012 movies
SELECT avg(rating) FROM ratings JOIN movies ON ratings.movie_id = movies.id WHERE year = 2012;