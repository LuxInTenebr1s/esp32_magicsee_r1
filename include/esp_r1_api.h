#ifndef __ESP_R1_API_H__
#define __ESP_R1_API_H__

#define R1_EVENTS_TABLE       \
    X(R1_BUTTON1)             \
    X(R1_BUTTON2)             \
    X(R1_BUTTON3)             \
    X(R1_BUTTON4)             \
    X(R1_BUTTON5)             \
    X(R1_BUTTON6)             \
    X(R1_BUTTON7)             \
    X(R1_BUTTON8)             \
    X(R1_BUTTON9)             \
    X(R1_BUTTON10)            \
    X(R1_BUTTON11)            \
    X(R1_BUTTON12)            \
    X(R1_WHEEL)               \
    X(R1_AXIS_X)              \
    X(R1_AXIS_Y)              \
    X(R1_KBD_LEFT_CTRL)       \
    X(R1_KBD_LEFT_SHIFT)      \
    X(R1_KBD_LEFT_ALT)        \
    X(R1_KDB_LEFT_GUI)        \
    X(R1_KBD_RIGHT_CTRL)      \
    X(R1_KBD_RIGHT_SHIFT)     \
    X(R1_KBD_RIGHT_ALT)       \
    X(R1_KBD_RIGTH_GUI)       \
    X(R1_VOLUME_INCREMENT)    \
    X(R1_VOLUME_DECREMENT)    \
    X(R1_PLAY_PAUSE)          \
    X(R1_MUTE)                \
    X(R1_SCAN_PREV_TRACK)     \
    X(R1_SCAN_NEXT_TRACK)     \
    X(R1_AC_HOME)

/**
 * @brief Key IDs possible values
 */
typedef enum {
#define X(name) name,
R1_EVENTS_TABLE
#undef X
} esp_r1_key_id_t;

/**
 * @brief Key state possible values
 */
typedef enum {
    R1_KEY_RELEASED = 0U,
    R1_KEY_PRESSED  = 1U,
} esp_r1_key_state_t;

/**
 * @brief Structure to represent pointer event data
 */
typedef struct {
    int8_t x_axis;      /*!< X-axis relative value.                          */

    int8_t y_axis;      /*!< Y-axis relative value.                          */

    int8_t wheel;       /*!< Wheel encoder relative value.                   */

} esp_r1_pointer_data_t;

/**
 * @brief Structure to represent keyboard event data
 */
typedef struct {
    esp_r1_key_id_t id;         /*!< Current event key ID.                   */

    esp_r1_key_state_t state;   /*!< Key current state.                      */

} esp_r1_keyboard_data_t;

typedef void (*esp_r1_pointer_cb_t)(esp_r1_pointer_data_t*);

typedef void (*esp_r1_keyboard_cb_t)(esp_r1_keyboard_data_t*);

/**
 * @brief Initialize BLE and Bluedroid resources
 */
esp_err_t esp_r1_init(void);

/**
 * @brief Enable driver; it start searching, connecting and receiving data
 */
esp_err_t esp_r1_enable(void);

/**
 * @brief Register pointer device callback function
 */
esp_err_t esp_r1_pointerregister_callback(esp_r1_pointer_cb_t cb);

/**
 * @brief Register keyboard device callback function
 */
esp_err_t esp_r1_keyboard_register_callback(esp_r1_keyboard_cb_t cb);

/**
 * @brief Get event name by it's ID (send in keyboard data structure)
 */
const char* esp_r1_event_name_get_by_id(esp_r1_key_id_t id);

#endif
