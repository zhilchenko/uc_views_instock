<?php

/**
 * @file
 * Views handler: filter not in stock.
 */

class uc_views_instock_handler_filter_instock extends views_handler_filter_boolean_operator {
  function query() {
    // If checked
    if ($this->value) {
      $this->ensure_my_table();

      // Stock control inactive or active and stock value more than 0
      $clause = "NOT {$this->table_alias}.active OR ({$this->table_alias}.active AND {$this->table_alias}.stock > 0)";
      $this->query->add_where($this->options['group'], $clause);
    }
  }

  // We want checkbox instead select
  function exposed_form(&$form, &$form_state) {
    $form['instock']  = array(
      '#type' => 'checkbox',
      // Title set in views GUI
      '#title' => $this->options['expose']['label'],
    );
  }
}
