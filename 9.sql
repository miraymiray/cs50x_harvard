--print the 2004 movies stars' ordered by birth
SELECT DISTINCT(people.name) from stars JOIN people ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id WHERE movies.year = 2004 ORDER BY birth;