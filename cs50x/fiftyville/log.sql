-- Keep a log of any SQL queries you execute as you solve the mystery.
--All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.

-- Bakery mentioned, time of theift: 10:15am
SELECT * FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND year = 2021 AND street = 'Humphrey Street';

-- Ruth: car left bakery parking (10:15am - 10:25am)
-- Eugene: Emma's Bakery, saw thief at ATM(Legget Street) withdrawing money
-- Raymond: Thief called someone(For less than a min.).
-- They planned earliest flight out of Fiftyville next day.
-- Other person bought the ticket.
SELECT * FROM interviews
WHERE month = 7 AND day = 28 AND year = 2021;

-- ATM: person_id List from transactions
SELECT person_id AS atm_list
FROM bank_accounts
WHERE account_number IN
(
    SELECT account_number FROM atm_transactions
    WHERE month = 7 AND day = 28 AND year = 2021
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
)
;
-- person_id from license_plate at given time at bakery
SELECT id AS car_list
FROM people
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE month = 7 AND day = 28 AND year = 2021
    AND hour = 10 AND (minute > 14 OR minute < 26)
)
;

-- get caller_id and receiver_id from phone calls
SELECT caller_id, receiver_id
FROM (
    SELECT "caller", "receiver"
    FROM phone_calls
    WHERE month = 7
    AND day = 28
    AND year = 2021
    AND duration < 60
) AS call_details
JOIN (
    SELECT phone_number AS number, id AS caller_id
    FROM people
) AS caller_details
ON call_details.caller = caller_details.number
JOIN (
    SELECT phone_number AS number, id AS receiver_id
    FROM people
) AS receiver_details
ON call_details.receiver = receiver_details.number
;


-- person_id from passengers from next day 1st flight
SELECT id, passport_number
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE origin_airport_id = (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        AND month = 7
        AND day = 29
        AND year = 2021
        ORDER BY hour, minute
        LIMIT 1
    )
)
;


-- JOIN car_list and atm_list and calls_list and passengers_list
SELECT *
FROM (
    SELECT person_id AS atm_list
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE month = 7
        AND day = 28
        AND year = 2021
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
) AS atm_list
JOIN (
    SELECT id AS car_list, name AS thief
    FROM people
    WHERE license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE month = 7
        AND day = 28
        AND year = 2021
        AND hour = 10
        AND (minute > 14 AND minute < 26)
    )
) AS car_list
ON atm_list.atm_list = car_list.car_list
JOIN (
    SELECT id AS passengers_list
    FROM people
    WHERE passport_number IN
    (
        SELECT passport_number
        FROM passengers
        WHERE flight_id =
        (
            SELECT id
            FROM flights
            WHERE origin_airport_id =
            (
                SELECT id
                FROM airports
                WHERE city = 'Fiftyville'
            )
            AND month = 7
            AND day = 29
            AND year = 2021
            ORDER BY hour, minute
            LIMIT 1
        )
    )
) AS passengers_list
ON atm_list.atm_list = passengers_list.passengers_list
JOIN (
    SELECT caller_id, receiver_id, accomplice
    FROM (
        SELECT "caller", "receiver"
        FROM phone_calls
        WHERE month = 7
        AND day = 28
        AND year = 2021
        AND duration < 60
    ) AS call_details
    JOIN (
        SELECT phone_number AS number, id AS caller_id
        FROM people
    ) AS caller_details
    ON call_details.caller = caller_details.number
    JOIN (
        SELECT phone_number AS number, id AS receiver_id, name AS accomplice
        FROM people
    ) AS receiver_details
    ON call_details.receiver = receiver_details.number
) AS callings
ON atm_list.atm_list = callings.caller_id
;

--
--
SELECT *
FROM (
    SELECT *
    FROM passengers
    WHERE passport_number IN (
        SELECT passport_number
        FROM people
        WHERE id IN (864400,250277)
    )
) AS two
JOIN (
    SELECT id, passport_number
    FROM people
    WHERE passport_number IN
    (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = 36
    )
) AS psgrs
ON two.passport_number = psgrs.passport_number
;


SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE id IN (
        SELECT id
            FROM flights
            WHERE origin_airport_id = (
                SELECT id
                FROM airports
                WHERE city = 'Fiftyville'
            )
            AND month = 7
            AND day = 29
            AND year = 2021
            ORDER BY hour, minute
            LIMIT 1
    )
)
;
