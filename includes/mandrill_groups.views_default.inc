<?php
/**
 * @file
 * Default views configuration for Mandrill Groups module.
 */

/**
 * Implements hook_views_default_views().
 */
function mandrill_groups_views_default_views() {
  // Begin copy and paste of output from the Export tab of a view.
  $view = new view();
  $view->name = 'discussions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Discussions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = t('Discussions');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
    'flagged' => 'flagged',
    'ops' => 'flagged',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'flagged' => array(
      'align' => '',
      'separator' => ' |',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Flags: follow */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = t('following');
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'follow';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = t('Comments');
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = t('Last Comment');
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'today time ago';
  $handler->display->display_options['fields']['last_updated']['custom_date_format'] = 'j/n/Y G:i';
  $handler->display->display_options['fields']['last_updated']['second_date_format_custom'] = 'j/n/Y G:i';
  $handler->display->display_options['fields']['last_updated']['second_date_format'] = 'custom';
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Following';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Sort criterion: Flags: Flagged */
  $handler->display->display_options['sorts']['flagged']['id'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['table'] = 'flagging';
  $handler->display->display_options['sorts']['flagged']['field'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['flagged']['order'] = 'DESC';
  $handler->display->display_options['sorts']['flagged']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['flagged']['expose']['label'] = 'Following';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Contextual filter: Field: Mandrill Group Membership (mandrill_groups_og_ref) */
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['id'] = 'mandrill_groups_og_ref_target_id';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['table'] = 'field_data_mandrill_groups_og_ref';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['field'] = 'mandrill_groups_og_ref_target_id';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['validate_options']['types'] = array(
    'mandrill_groups_group' => 'mandrill_groups_group',
  );
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['mandrill_groups_og_ref_target_id']['validate']['fail'] = 'access denied';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mandrill_groups_discussion' => 'mandrill_groups_discussion',
  );

  /* Display: Discussion Summary Page */
  $handler = $view->new_display('page', 'Discussion Summary Page', 'mandrill_groups_discussions');
  $handler->display->display_options['path'] = 'node/%/discussions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = t('Discussions');
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  // (Export ends here.)

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  return $views;
  
}
