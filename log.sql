-- description
SELECT description
FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";
-- transcript
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE "%courthouse%";
-- suspect
WITH suspect_account_number AS (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"),
suspect_person_id AS (SELECT person_id FROM bank_accounts WHERE account_number IN suspect_account_number),
suspect_license_plate AS (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 10 AND 20),
suspect_phone_calls AS (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28) SELECT *FROM people WHERE id IN suspect_person_id AND license_plate IN suspect_license_plate AND phone_number IN suspect_phone_calls;
WITH suspect_accomplice_phone_number AS (SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND caller = "(367) 555-5533" AND duration <= 60) SELECT * FROM people WHERE phone_number IN suspect_accomplice_phone_number;
--courthouse security
SELECT * FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND license_plate IN ("V4C670D", "81MZ921", "4V16VO0", "10I5658");
WITH earliest_flight_id AS (SELECT destination_airport_id FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") ORDER BY hour LIMIT 1)
--selecting
SELECT * FROM airports WHERE id IN earliest_flight_id;