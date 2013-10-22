(ns sos.core
  (:require
    [clodiuno.core :refer :all]
    [clodiuno.firmata :refer :all]))

(def pin 11)
(def short-pulse 250)
(def long-pulse 500)
(def letter-delay 1000)

(def letter-s [0 0 0])
(def letter-o [1 1 1])

(defn blink [board time]
  (digital-write board pin HIGH)
  (Thread/sleep time)
  (digital-write board pin LOW)
  (Thread/sleep time))

(defn blink-letter [board letter]
  (doseq [i letter]
    (if (= i 0)
      (blink board short-pulse)
      (blink board long-pulse)))
  (Thread/sleep letter-delay))

(defn sos []
  (let [board (arduino :firmata "/dev/tty.usbmodem1421")]
    ;; allow arduino to boot
    (Thread/sleep 5000)
    (pin-mode board pin OUTPUT)

    (doseq [_ (range 3)]
      (blink-letter board letter-s)
      (blink-letter board letter-o)
      (blink-letter board letter-s))

    (close board)))

(def board (arduino :firmata "/dev/tty.usbmodem1421"))
(digital-write board pin LOW)
(close board)

(future
  (let [board (arduino :firmata "/dev/tty.usbmodem1421")]
    (Thread/sleep 5000)
    (pin-mode board pin OUTPUT)
    (doseq [_ (range 3)]
      (blink-letter board letter-s)
      (blink-letter board letter-o)
      (blink-letter board letter-s))
    (close board)))
