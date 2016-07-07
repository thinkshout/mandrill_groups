<?php

/**
 * Respond to a message bouncing.
 *
 * @param array $message
 *   The Mandrill message that bounced.
 * @param OgMembership $membership
 *   Fully loaded OG membership object.
 */
function hook_mandrill_groups_process_bounce($message, $membership) {

}

/**
 * Alter the text used to fill in 'Submitted by:' in outgoing comment emails.
 *
 * @param string $sender_name
 *   The sender's name from entity label.
 * @param object $author
 *   User object - the author of comment.
 */
function hooks_mandrill_groups_sender_alter(&$sender_name, $author) {

}
