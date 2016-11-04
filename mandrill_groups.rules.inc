<?php
/**
 * @file
 * Mandrill Groups rules file.
 */

/**
 * Implements hook_rules_event_info().
 */
function mandrill_groups_rules_event_info() {
  $info = array();

  $info['mandrill_groups_digest_response'] = array(
    'group' => t('Mandrill Groups'),
    'label' => t('After a response to daily digest'),
    'help' => t('Triggers when a user responds to Mandrill Groups daily digest email.'),
    'variables' => array(
      'responding_user' => array(
        'type' => 'user',
        'label' => t('responding user'),
      ),
    ),
  );

  return $info;
}