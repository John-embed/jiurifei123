

/** Abstraction that describes a Mesh Model instance */
struct bt_mesh_model {
	union {
		const u16_t id;
		struct {
			u16_t company;
			u16_t id;
		} vnd;
	};

	/* Internal information, mainly for persistent storage */
	u8_t  elem_idx;   /* Belongs to Nth element */
	u8_t  mod_idx;    /* Is the Nth model in the element */
	u16_t flags;      /* Information about what has changed */

	/* Model Publication */
	struct bt_mesh_model_pub * const pub;

	/* AppKey List */
	u16_t keys[CONFIG_BT_MESH_MODEL_KEY_COUNT];

	/* Subscription List (group or virtual addresses) */
	u16_t groups[CONFIG_BT_MESH_MODEL_GROUP_COUNT];

	const struct bt_mesh_model_op * const op;

	/* Model-specific user data */
	void *user_data;
};
