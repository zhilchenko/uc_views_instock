<?php

/**
 * @file
 * Views hooks and callback registries.
 */

/**
 * Implements hook_views_data().
 */
function uc_views_instock_views_data() {
  return array(
    'uc_product_stock' => array(
      'instock' => array(
        'group'  => t('Stock'),
        'title'  => t('In stock'),
        'help'   => t('Stock control is inactive or product in stock'),
        'filter' => array(
          'handler' => 'uc_views_instock_handler_filter_instock',
          'label'   => t('In stock'),
          'accept_null' => TRUE
          ),
      )
    )
  );
}

/**
 * Implements hook_views_handlers().
 */
function uc_views_instock_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'uc_views_instock'),
    ),
    'handlers' => array(
      'uc_views_instock_handler_filter_instock' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    ),
  );
}
