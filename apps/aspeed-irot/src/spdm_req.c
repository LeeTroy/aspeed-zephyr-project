#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <library/spdm_requester_lib.h>
#include <stdlib.h>

LOG_MODULE_REGISTER(spdm_req, LOG_LEVEL_DBG);

static void *spdm_req_ctx;


libspdm_return_t spdm_device_send_message(void *spdm_context,
		size_t message_size,
		const void *message,
		uint64_t timeout)
{
	LOG_DBG("Sending message of size %d", message_size);
	return LIBSPDM_STATUS_SUCCESS;
}

libspdm_return_t spdm_device_receive_message(void *spdm_context,
		size_t *message_size,
		void **message,
		uint64_t timeout)
{
	LOG_DBG("Receiving message");
	return LIBSPDM_STATUS_SUCCESS;
}

static int spdm_req_init(void)
{
	spdm_req_ctx = malloc(libspdm_get_context_size());
	if (spdm_req_ctx == NULL) {
		LOG_ERR("Failed to allocate SPDM requester context");
		return -ENOMEM;
	}

	libspdm_init_context(spdm_req_ctx);

	libspdm_register_device_io_func(spdm_req_ctx, spdm_device_send_message, spdm_device_receive_message);

	return 0;
}

SYS_INIT(spdm_req_init, APPLICATION, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
