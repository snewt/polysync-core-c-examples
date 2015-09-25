/**
 * @file ps_interface.h
 * @brief PolySync Interface.
 *
 * @todo fix docs.
 *
 */




#ifndef PS_INTERFACE_H
#define	PS_INTERFACE_H




#include <glib-2.0/glib.h>
#include "polysync_core.h"

#include "gui.h"





typedef struct
{
    //
    //
    ps_node_ref node;
    //
    //
    GAsyncQueue *msg_queue;
    //
    //
    ps_msg_type msg_type_radar_targets;
} node_data_s;



/**
 * @brief Node name string.
 *
 */
extern const char       PS_NODE_NAME[];


/**
 * @brief PolySync radar targets message name.
 *
 */
extern const char       PS_RADAR_TARGETS_MSG_NAME[];




/**
 * @brief Initialize PolySync resources.
 *
 * Sets up data handler(s) and data queue for incoming messages.
 *
 * @return A newly created PolySync message queue on success, NULL on failure.
 *
 */
node_data_s *init_polysync( void );


/**
 * @brief Release PolySync resources.
 *
 * Free's any messages in the data queue.
 *
 * @param [in] msg_queue A pointer to GAsyncQueue which possibly contains PolySync messages.
 *
 */
void release_polysync( node_data_s * const node_data );


/**
 * @brief Process a PolySync message.
 *
 * Dequeue a message (if any) from a data queue and process it into GUI objects
 * base on the type.
 *
 * @param [in] gui A pointer to \ref gui_context_s which specifies the configuration(s).
 * @param [in] msg_queue A pointer to GAsyncQueue which specifies the message queue to read from.
 * @param [in] parent_list A pointer to GList which specifies the parent entities list.
 * @param [in] update_time Update timestamp to give objects.
 * @param [out] msg_read A pointer to unsigned int which receives the message processed status.
 * Value one means a message was processed. Value zero means no messages were available.
 *
 * @return The (possibly new) parent entities list, NULL means empty list.
 *
 */
GList *ps_process_message( node_data_s * const node_data, const gui_context_s * const gui, GList * const parent_list, const unsigned long long update_time, unsigned int * const msg_read );




void ps_register_listener( const ps_msg_type type, GAsyncQueue * const msg_queue );


void ps_unregister_listener( const ps_msg_type type );




#endif	/* PS_INTERFACE_H */
